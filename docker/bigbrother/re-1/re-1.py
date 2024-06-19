from pwn import * 
p=remote("bigbrother-re-1.chals.io", 443, ssl=True, sni="bigbrother-re-1.chals.io")
p.interactive()
