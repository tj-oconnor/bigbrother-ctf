from pwn import * 
p=remote("bigbrother-re-3.chals.io", 443, ssl=True, sni="bigbrother-re-3.chals.io")
p.interactive()