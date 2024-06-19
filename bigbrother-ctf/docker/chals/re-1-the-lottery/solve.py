from pwn import * 
p=remote("fitsec-bb-re-1.chals.io", 443, ssl=True, sni="fitsec-bb-re-1.chals.io")
p.interactive()