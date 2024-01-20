#include <stdio.h>

  int main()
  {
      char buf[64] = "abc\taaa bbb\tcc dd";
      // f1:abc   f2:aaa bbb   f3:cc dd 
      char f1[32], f2[32], f3[32];
     sscanf(buf, "%[^\t]\t%[^\t]\t%[^\t]", f1, f2, f3);
      printf("%s|%s|%s\n", f1, f2, f3);
      return 0;
  }