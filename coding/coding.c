#include "coding.h"
  void coding(char *src, char *key, char *dst, int srclen) {
      int i = 0;
      int klen = strlen(key);
      for(int i=0; i<srclen; i++) {
          dst[i] = src[i] ^ key[i % klen];
      }
      dst[srclen] = 0;
  }