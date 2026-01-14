### memdump (easy)

This exercise will give you more practice using C pointers. Before starting read section 5.1 (Pointers and addresses) through 5.6 (Pointer arrays) and 6.4 (pointers to structures) in "The C programming language (second edition)" by Kernighan and Ritchie (K&R).

Have a look at user/memdump.c. Your job is to implement the function memdump(char *fmt, char *data). memdump()'s purpose is to print the contents of the memory pointed to by data in the format described by the fmt argument. The format is a C string. Each character of the string indicates how to print successive parts of the data. Thus, for example, a C struct with multiple fields can be printed with a format string containing multiple characters.

Your memdump() should handle the following format characters:

    i: print the next 4 bytes of the data as a 32-bit integer, in decimal.
    p: print the next 8 bytes of the data as a 64-bit integer, in hex.
    h: print the next 2 bytes of the data as a 16-bit integer, in decimal.
    c: print the next 1 byte of the data as an 8-bit ASCII character.
    s: the next 8 bytes of the data contain a 64-bit pointer to a C string; print the string.
    S: the rest of the data contains the bytes of a null-terminated C string; print the string. 

Feel free to use C's printf() in your memdump().

The memdump program, if executed with no arguments, calls memdump() with some example format strings and data. If memdump() is correctly implemented, the output will be:
```
$ memdump
Example 1:
61810
2025
Example 2:
a string
Example 3:
another
Example 4:
BD0
1819438967
100
z
xyzzy
Example 5:
hello
w
o
r
l
d
```
You will likely get a different hex address for the first line of the Example 4 output.

If the memdump program is invoked with an argument, it will read its standard input up to an end of file, and then call memdump() with the format and input data. So, once memdump() is implemented:
```
$ echo deadc0de | memdump hhcccc
25956
25697
c
0
d
e
$ echo deadc0de | memdump p
64616564
$ 
```
Implement memdump(). 
