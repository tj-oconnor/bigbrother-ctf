# forensics-1: take a *bin*walk

<img src="images/forensics-1.jpg"></img>

## Prompt 

Some say the **Ministry of Peace** concerns itself with war. Take a **WALK** with us. Like all good hackers, *we concern ourselves with capturing flags.* Do you want to join the Ministry? Capture the flag from the attached file.


## Solution

The file has been compressed using tar, gz, bz2, zip. We can use [binwalk](https://github.com/ReFirmLabs/binwalk) to recursively decompress the file and return the flag. 

```
binwalk -eM flag.flag
cd _flag.tar.gz.bz2.zip.extracted/_flag.tar.gz.bz2.extracted/_0.extracted/_0.extracted/flag
cat flag.txt
```
