# web-2: Only Admin's

<img src="images/web-2.jpg"></img>

## Prompt 

The **Ministry of Null** invites you to the **Big Brother's Cookie Web Store!** Our store is known for its secret ingredient that makes our cookies unique and delicious. However, only the admin has access to this secret ingredient.

https://bigbrother-web-2.chals.io

## Solution

Going to ``https://bigbrother-web-2.chals.io/robots.txt``, we see that there is a page called ``/admin`` that is protected. However, when we enter this page, it tells us only administrators are allowed. Luckily, there is a [cookie](https://en.wikipedia.org/wiki/HTTP_cookie) for ``admin:false``. If we use the web developer add-on to modify our cookies and set ``admin:true``. 
