from pwn import * 
p=remote("fitsec-bb-re-3.chals.io", 443, ssl=True, sni="fitsec-bb-re-3.chals.io")
p.interactive()