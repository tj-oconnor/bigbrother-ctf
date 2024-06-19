# re-1: the lottery

<img src="images/re-1.jpg"></img>

## Prompt 

The **Ministry of Plenty** Invites you to play the lottery on the following remote system. Reverse engineer the attached linux binary for the best results. Big brother grants you the following code to connect to the remote server where a copy of the program is running and storing a **plenti**ful flag. 

```python
from pwn import * 
p=remote("bigbrother-re-1.chals.io", 443, ssl=True, sni="bigbrother-re-1.chals.io")
p.interactive()
```
## Solution

The program generates a random number displayed to the user; it then adds that number to the user input. If the sum == 0x31337, the program displays the flag. 

```
mov     edx, dword [rbp-0x8 {var_10}]
mov     eax, dword [rbp-0x4 {var_c_1}]
add     eax, edxcmp     eax, 0x31337
jne     0x401695
lea     rax, [rel data_402e90] {"cat flag.txt"}
mov     rdi, rax {data_402e90, "cat flag.txt"}
call    system
```

We can automate solving the problem using pwntools. Here, we receive the random integer and then submit the correct value (0x31337-rand_value) to the server. 

```python
from pwn import *
p=remote("bigbrother-re-1.chals.io", 443, ssl=True, sni="bigbrother-re-1.chals.io")
p.recvuntil(b'random integer: ')
rand_value = int(p.recvline())
p.sendline(b'%i' %(0x31337-rand_value))
p.interactive()
```
