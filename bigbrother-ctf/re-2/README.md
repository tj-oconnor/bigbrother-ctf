# re-2: food rationing

<img src="images/re-2.jpg"></img>

## Prompt 

The **Ministry of Plenty** has an offline food rationing system. Rumors have circulated around Oceania for decades of a secret password that grants you flag. However, the Ministry has compiled the binary with only MOV instructions, preventing any static analysis. Youl**L** need to **trace** the binary another way to determine the password and capture the flag. 


## Solution

Disassembling the program, we see it has been compiled with [movofuscator](https://github.com/xoreaxeaxeax/movfuscator), complicating static analysis. Instead, we can dynamically trace the library calls using [ltrace](https://en.wikipedia.org/wiki/Ltrace). The program prompts for a user input, and we'll enter ``AAAAAAAAAA`` and see if there are any library calls that include ``AAAAAAAAAA``. 

We see that ``AAAAAAAAAA`` is compared against ``B1gBr0th3R`` using the [strncmp](https://en.cppreference.com/w/c/string/byte/strncmp) function. This must be a check for the password. 

```
ltrace ./re-2.bin
...
strncmp("AAAAAAAAAA\365\367B1gBr0th3R", "B1gBr0th3R", 9)
```

Testing ``B1gBr0th3R``, we receive the flag.

```
 Please login >>> B1gBr0th3R
<<< We have won the battle for production! : bbctf{h1S_W1s3_l3ad3rsh1p}
```
