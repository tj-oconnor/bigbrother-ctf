with open('flag.bmp', 'rb') as png_header:
    header_bytes = png_header.read(100)

with open('flag.enc', 'rb') as encrypted_file:
    encrypted_bytes = encrypted_file.read()

with open('flag-recovered.bmp', 'wb') as output_file:
    output_file.write(header_bytes)
    output_file.write(encrypted_bytes[8:])
