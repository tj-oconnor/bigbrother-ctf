from pwn import * 
p=remote("bigbrother-pwn-2.chals.io", 443, ssl=True, sni="bigbrother-pwn-2.chals.io")
p.interactive()
