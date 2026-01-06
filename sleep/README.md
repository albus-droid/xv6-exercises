### sleep (easy)

This exercise makes you familiar with writing a user program on xv6 and the pause system call.

Implement a user-level sleep program for xv6, along the lines of the UNIX sleep command. Your sleep should pause for a user-specified number of ticks. A tick is a notion of time defined by the xv6 kernel, namely the time between two interrupts from the timer chip. Your solution should be in the file user/sleep.c.

Some hints:

    Before you start coding, read Chapter 1 of the xv6 book.
    Put your code in user/sleep.c. Look at some of the other programs in user/ (e.g., user/echo.c, user/grep.c, and user/rm.c) to see how command-line arguments are passed to a program.
    Add your sleep program to UPROGS in Makefile; once you've done that, make qemu will compile your program and you'll be able to run it from the xv6 shell.
    If the user forgets to pass an argument, sleep should print an error message.
    The command-line argument is passed as a string; you can convert it to an integer using atoi (see user/ulib.c).
    Use the system call pause().
    See kernel/sysproc.c for the xv6 kernel code that implements the pause() system call (look for sys_pause), user/user.h for the C definition of pause() callable from a user program, and user/usys.S for the assembler code that jumps from user code into the kernel for pause().
    Look at Kernighan and Ritchie's book The C programming language (second edition) (K&R) to learn about C. 

Run the program from the xv6 shell:
```
      $ make qemu
      ...
      init: starting sh
      $ sleep 10
      (nothing happens for a little while)
      $
```    
Your program should pause when run as shown above. Run make grade in your command line (outside of qemu) to see if you pass the sleep tests.

Note that make grade runs all tests, including the ones for the tasks below. If you want to run the grade tests for one task, type:

     $ ./grade-lab-util sleep
     
This will run the grade tests that match "sleep". Or, you can type:

     $ make GRADEFLAGS=sleep grade
     
which does the same. 
