### sixfive (moderate)

In this exercise you'll use the system calls open and read, C strings, and processing text files in C.

For each input file, sixfive must print all the numbers in the file that are multiples of 5 or 6. Number are a sequence of decimal digits separated by characters in the string " -\r\t\n./,". Thus, for the six in "xv6" sixfive shouldn't print 6 but, for example, "/6," it should.
The following example illustrates sixfive's behavior:
```
    $ sixfive sixfive.txt
    5
    100
    18
    6
    $
```  

Some hints:

    Read the input file a character at the time
    You can test if a character matches any of the separators using strchr (see user/ulib.c).
    Start and end of file are implicit separators. 