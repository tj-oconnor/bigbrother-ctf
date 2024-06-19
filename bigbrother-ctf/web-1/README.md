# web-1: Big Brother's Command

<img src="images/web-1.jpg"></img>

## Prompt 

The **Ministry of Null** proudly presents an extraordinary website that allows you to ping anyone. However, rumor has it that the website harbors a hidden bounty of exclusive information, accessible only by invoking Big Brother's commands. Venture forth and tread carefully, for the secrets that await may not be for the faint of heart. 
https://bigbrother-web-1.chals.io

## Solution

The problem suffers a [command injection vulnerability](https://owasp.org/www-community/attacks/Command_Injection). You can take advantage of it by concatenating the expected input with a second command. For example ``127.0.0.1; cat flag.txt`` will display the flag.  
