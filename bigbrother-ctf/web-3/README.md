# web-3: Database Duty of Oceania

<img src="images/web-3.jpg"></img>

## Prompt 

Amidst tragic events, it has come to light that the database belonging to the **Ministry of Null** has been compromised, revealing their deepest secrets. There are whispers that one of the organizers may have inadvertently stored confidential information in the database. Their database is now open for the public, and it is said that hidden within it lies a treasure trove of information that only the astute can uncover. As you dig deeper into the database, remember that **Big Brother's watchful eyes are always upon you**.

https://bigbrother-web-3.chals.io

## Solution

The page suffers a [SQL-injection](https://owasp.org/www-community/attacks/SQL_Injection) vulnerability. It is expecting a string that will be added to a query. We can concentrate the string to a qualifier that always results in true, thus displaying all the flags. Testing a few inputs, we finally see ``1" or 1==1 --`` yields all the records. 
