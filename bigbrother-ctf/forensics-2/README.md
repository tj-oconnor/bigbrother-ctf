# forensics-2: thought criminal memory

<img src="images/forensics-2.jpg"></img>

## Prompt 

The **Ministry** has captured one of the Brotherhood. We've dumped the memory image from the **thought criminals** laptop and want to know more about the server he's connected to and what type of propaganda he is spreading. 

## Solution

The memory snapshot is from a Windows XP machine. Using [volatility](https://github.com/volatilityfoundation/volatility), we can do a scan of the connections. If we connect to ``165.227.210.30 19889`` using [netcat](https://netcat.sourceforge.net), we see it displays the flag.  

```
vol.py -f snapshot.vmem connscan

Volatility Foundation Volatility Framework 2.6.1
Offset(P)  Local Address             Remote Address            Pid
---------- ------------------------- ------------------------- ---
0x01f9f008 172.16.145.132:1049       140.82.114.3:443          276
0x01fc6bb0 172.16.145.132:1041       172.217.2.195:80          276
0x01ff0700 172.16.145.132:1035       165.227.210.30:19889      1128
0x024424b0 172.16.145.132:1034       192.168.1.127:80          1932


# nc 165.227.210.30 19889          
..........bbctf{Ours_1s_f0und3d_upon_h4tREd}..........^C
```
