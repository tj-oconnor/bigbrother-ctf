# crypto-2: room 101

<img src="images/crypto-2.jpg"></img>

## Prompt

The **Ministry of Love** protects you from the thought criminals with **XOR-grade randomized encryption** at our **Room-101**. Connect to the Ministry's server using the command ``nc 0.cloud.chals.io 19977`` (or using the code below) and protect your secrets from the **thought criminals.**

```python
from pwn import * 
p=remote("0.cloud.chals.io",19977)
p.interactive()
```

## Solution

Connect to the server we see some encrypted text printed out.

```
<<< Ministry of Love has securely stored the flag from thought criminals: ['61', '61', '60', '77', '65', '78', '77', '6b', '66', '5c', '61', '66', '62', '77', '6a', '6d', '64', '70', '5c', '64', '71', '66', '74', '5c', '6f', '66', '70', '70', '5c', '65', '71', '66', '72', '76', '66', '6d', '77', '7e']
```

Using a known-plaintext attack, we see that that if we encrypted ``bbctf``, it yields the first five encrypted values. 

```
Enter Your Secrets to Encrypt >>> $ bbctf
<<< Your data is safe from the thought criminals: ['61', '61', '60', '77', '65']
```

We can further use this approach to build an alphabet that matches all the ``string.printable`` characters to their encrypted values.

```
Enter Your Secrets to Encrypt >>> $ 0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ!"#$%&'()*+,-./:;<=>?@[\]^_`{|}~
<<< Your data is safe from the thought criminals: ['33', '32', '31', '30', '37', '36', '35', '34', '3b', '3a', '62', '61', '60', '67', '66', '65', '64', '6b', '6a', '69', '68', '6f', '6e', '6d', '6c', '73', '72', '71', '70', '77', '76', '75', '74', '7b', '7a', '79', '42', '41', '40', '47', '46', '45', '44', '4b', '4a', '49', '48', '4f', '4e', '4d', '4c', '53', '52', '51', '50', '57', '56', '55', '54', '5b', '5a', '59', '22', '21', '20', '27', '26', '25', '24', '2b', '2a', '29', '28', '2f', '2e', '2d', '2c', '39', '38', '3f', '3e', '3d', '3c', '43', '58', '5f', '5e', '5d', '5c', '63', '78', '7f', '7e', '7d']
```

We could use this to lookup all the values in the encrypted flag. We write a small Python3 program to help us do that. 

```python
import string

flag = ['61', '61', '60', '77', '65', '78', '77', '6b', '66', '5c', '61', '66', '62', '77', '6a', '6d', '64', '70',
        '5c', '64', '71', '66', '74', '5c', '6f', '66', '70', '70', '5c', '65', '71', '66', '72', '76', '66', '6d', '77', '7e']

plaintext_charset = string.printable

encrypted_charset = ['33', '32', '31', '30', '37', '36', '35', '34', '3b', '3a', '62', '61', '60', '67', '66', '65', '64', '6b', '6a', '69', '68', '6f', '6e', '6d', '6c', '73', '72', '71', '70', '77', '76', '75', '74', '7b', '7a', '79', '42', '41', '40', '47', '46', '45', '44', '4b', '4a',
                     '49', '48', '4f', '4e', '4d', '4c', '53', '52', '51', '50', '57', '56', '55', '54', '5b', '5a', '59', '22', '21', '20', '27', '26', '25', '24', '2b', '2a', '29', '28', '2f', '2e', '2d', '2c', '39', '38', '3f', '3e', '3d', '3c', '43', '58', '5f', '5e', '5d', '5c', '63', '78', '7f', '7e', '7d']

for element in flag:
    print(plaintext_charset[encrypted_charset.index(element)], end='')
```

Running this produces the flag
```
 python3 solution.py
bbctf{the_beatings_grew_less_frequent}
```