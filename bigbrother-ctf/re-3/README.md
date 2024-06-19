# re-3: grain production

<img src="images/re-3.jpg"></img>

## Prompt 

The **Ministry of Plenty** Invites you to report grain production on the following remote system. Reverse engineer the attached linux binary for the best results. Big brother grants you the following code to connect to the remote server where a copy of the program is running and storing a **plenti**ful flag. 

```python
from pwn import * 
p=remote("bigbrother-re-3.chals.io", 443, ssl=True, sni="bigbrother-re-3.chals.io")
p.interactive()
```

## Solution

Examining the binary, we it is expecting five values 

```lea     rax, [rel data_402d66] {"%d,%x,%d,%x,%x"}```

This is following by five comparisons, that check the values against the values [0x2,0x31337,0x2,0x5,0x1337].

We can automate the process of sending these values using a pwntools script. 

```python
from pwn import * 
p=remote("bigbrother-re-3.chals.io", 443, ssl=True, sni="bigbrother-re-3.chals.io")
p.sendline(b'%d,%x,%d,%x,%x' %(2,0x31337,2,5,0x1337))
p.interactive()
```

Running this script produces the flag. 
