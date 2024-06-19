# crypto-3: unrECoveraBle

<img src="images/crypto-3.jpg"></img>

## Prompt 

The **Ministry of Love** has randomly encrypted a flag with ``AES-ECB`` with a random key, making it unr**EC**overa**B**le. Take the power back and recover the flag. [flag.enc](https://fitsec.ctfd.io/files/8fc0ef2e23ee6fad32a776a8851937aa/flag.enc) is the encrypted flag. [example.tar.gz](https://fitsec.ctfd.io/files/81e448e6426fd96e9b6a4398d539dd11/example.tar.gz) is an example of how the code randomly encrypts a fake-flag. 


## Solution

The encrypted image uses a [weak cryptographic blocking method](https://en.wikipedia.org/wiki/Block_cipher_mode_of_operation) that can reveal the contents of the image even if its encrypted. 

If we just repair the [file header](https://en.wikipedia.org/wiki/File_format) of the image, by copying over the sample flag, we can recover the image. 

```python
with open('flag.bmp', 'rb') as png_header:
    header_bytes = png_header.read(100)

with open('flag.enc', 'rb') as encrypted_file:
    encrypted_bytes = encrypted_file.read()

with open('flag-recovered.bmp', 'wb') as output_file:
    output_file.write(header_bytes)
    output_file.write(encrypted_bytes[8:])
```