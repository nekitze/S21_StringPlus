#include "s21_string.h"

void *s21_memchr(const void *str, int c, s21_size_t n) {
  const unsigned char *ptr = str;
  while (n--) {
    if (*ptr == (unsigned char)c) {
      return (void *)ptr;
    }
    ptr++;
  }
  return NULL;
}
