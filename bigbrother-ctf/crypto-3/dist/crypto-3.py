from PIL import Image, ImageDraw, ImageFont
from Crypto.Cipher import AES
import os
from Crypto.Util.Padding import pad, unpad
BLOCK_SIZE = 32

img = Image.open("225.bmp")
width, height = img.size

with open("flag.txt", "r") as f:
    flag_contents = f.read()

new_img = Image.new("RGBA", (width, height), (255, 255, 255, 0))
new_img.paste(img, (0, 0))
text_layer = Image.new("RGBA", (width, height), (255, 255, 255, 0))
draw = ImageDraw.Draw(text_layer)
chalk = ImageFont.truetype("Chalkduster.ttf",64)
draw.text((50, 50), flag_contents, fill=(255, 0, 0, 255),font=chalk)
new_img = Image.alpha_composite(new_img, text_layer)
new_img.save("flag.bmp")

new_img_contents = open("flag.bmp","rb").read()
key = os.urandom(16) 
cipher = AES.new(key, AES.MODE_ECB)
encrypted_data = cipher.encrypt(pad(new_img_contents,BLOCK_SIZE))
with open("flag.enc", "wb") as f:
    f.write(encrypted_data)