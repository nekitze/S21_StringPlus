#include "s21_string.h"

char *s21_strchr(const char *str, int c) {
  char *res = S21_NULL;
  while ((*str != '\0') && (*str != c)) {
    str++;
  }
  if (*str == c) {
    res = (char *)str;
  }
  return res;
}
