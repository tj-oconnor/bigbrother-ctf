from pwn import * 
p=remote("bigbrother-pwn-1.chals.io", 443, ssl=True, sni="bigbrother-pwn-1.chals.io")
p.interactive()