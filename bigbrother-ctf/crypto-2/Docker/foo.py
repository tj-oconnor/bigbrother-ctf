from pwn import * 
p=remote("bigbrother-crypto-2.chals.io", 443, ssl=True, sni="bigbrother-crypto-2.chals.io")
p.interactive()
