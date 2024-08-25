#include "coding/coding.h"
  int main()
  {
      char crypto [] = {27,17,25,8,22,72,6,76,0,14,6,2,25,13,8,13,69,28,30,0,15,23,13,1,67,26,10,15,4,10,27,17,9,30,79,12,23,5,26,10,72,86,95};
      char plain [] = "study c language program,rochester drive 33";
      char *k = "hello";
      char d[64];
      int  sl = sizeof(crypto);
      int sl2 = sizeof(plain);

      coding(crypto, k, d, sl);
      printf("%s ", d);
      printf("\n");
      coding(plain, k, d, sl2);
      for(int i=0; i<sl2-1; i++){
        printf("%d ", *(d+i));
      }
      printf("\n");
      return 0;
  }