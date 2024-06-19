└─# volatility -f brotherhood-xp.vmem connscan
Volatility Foundation Volatility Framework 2.6
Offset(P)  Local Address             Remote Address            Pid
---------- ------------------------- ------------------------- ---
0x09c1a6a0 192.168.47.139:1033       165.227.210.30:31251      2560
^CInterrupted

┌──(root㉿d74c92242115)-[~/workspace]
└─# nc 165.227.210.30 31251 
..................................bbctf{Ours_1s_f0und3d_upon_h4tREd}.....^C