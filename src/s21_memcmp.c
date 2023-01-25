#include "s21_string.h"

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  const unsigned char *str1_p = str1, *str2_p = str2;
  while (n--) {
    if (*str1_p != *str2_p) {
      return *str1_p - *str2_p;
    }
    str1_p++;
    str2_p++;
  }
  return 0;
}
