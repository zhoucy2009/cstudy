#include <string.h>
  #include <stdio.h>

  void encode(char *src, char *key, char *dst, int srclen) {
      int i = 0;
      int klen = strlen(key);
      for(int i=0; i<srclen; i++) {
          dst[i] = src[i] ^ key[i % klen];
      }
      dst[srclen] = 0;
  }

  int main()
  {
      char crypto [] = {27,17,25,8,22,72,6,76,0,14,6,2,25,13,8,13,69,28,30,0,15,23,13,1,67,26,10,15,4,10,27,17,9,30,79,12,23,5,26,10,72,86,95};
      char *k = "hello";
      char d[64];
      int  sl = sizeof(crypto);

      encode(crypto, k, d, sl);
      printf("%s ", d);
      printf("\n");

      return 0;
  }