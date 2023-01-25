#include "s21_string.h"

char *s21_strcat(char *destination, const char *source) {
  int last = s21_strlen(destination);
  int i = 0;
  while (source[i] != '\0') {
    destination[last] = source[i];
    i++;
    last++;
  }
  destination[last] = '\0';
  return destination;
}

char *s21_strncat(char *dest, const char *src, size_t n) {
  s21_size_t count = 0;
  if (!dest || !src) {
    exit(1);
  }
  for (s21_size_t i = s21_strlen(dest); count < n;) {
    dest[i] = src[count];
    count++;
    i++;
  }
  return dest;
}
