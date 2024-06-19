from pwn import * 
p=remote("bigbrother-pwn-3.chals.io", 443, ssl=True, sni="bigbrother-pwn-3.chals.io")
p.interactive()
