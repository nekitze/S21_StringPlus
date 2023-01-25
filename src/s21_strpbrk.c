#include "s21_string.h"

char *s21_strpbrk(const char *s, const char *accept) {
  while (*s != '\0') {
    const char *a = accept;
    while (*a != '\0')
      if (*a++ == *s) return (char *)s;
    s++;
  }
  return S21_NULL;
}
