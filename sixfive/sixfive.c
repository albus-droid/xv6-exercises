/* 
   For each input file, sixfive must print all the numbers in the file that are
   multiples of 5 or 6. Number are a sequence of decimal digits separated by
   characters in the string " -\r\t\n./,". Thus, for the six in "xv6" sixfive
   shouldn't print 6 but, for example, "/6," it should. 
*/

#include "kernel/types.h"
#include "kernel/stat.h"
#include "kernel/fcntl.h"
#include "user/user.h"

char buf[4096];

void sixfive(int fd, char *number) {
   
   int i, n, k = 0;
   char num[32];
   
   while((n = read(fd, buf, sizeof(buf))) > 0) {
      for (i = 0; i < n; i++) {
         if (strchr(" -\r\t\n./,^", buf[i])) {
               num[k] = '\0';
	       if (atoi(num) % 5 == 0 || atoi(num) % 6 == 0)
                  printf("%d\n", atoi(num));
	       k = 0;
	 }
	 else {
	       num[k++] = buf[i];
	 }
      }
   }   
	// Flush everything 
      if (k > 0) {
	num[k] = '\0';
	if (atoi(num) % 5 == 0 || atoi(num) % 6 == 0)
           printf("%d\n", atoi(num));
      }

   if (n < 0) {
      printf("sixfive : read error\n");
      exit(1);
   }
}

int main(int argc, char *argv[]) {

   if(argc < 2) {
     sixfive(0, "");
     exit(0);
  }

   for(int a = 1; a < argc; a++) {
      int fd = open(argv[a], O_RDONLY);
      if(fd < 0) {
        printf("sixfive: cannot open %s\n", argv[a]);
        exit(1);
      }
      sixfive(fd, argv[a]);
      close(fd);
  } 
   exit(0);
}
