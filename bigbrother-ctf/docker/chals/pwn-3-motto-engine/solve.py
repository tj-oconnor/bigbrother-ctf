from pwn import * 
p=remote("fitsec-bb-pwn-3.chals.io", 443, ssl=True, sni="fitsec-bb-pwn-3.chals.io")
p.interactive()