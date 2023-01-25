#include "s21_string.h"

char *s21_strstr(const char *haystack, const char *needle) {
  size_t needle_len = s21_strlen(needle);
  if (needle_len == 0) {
    return (char *)haystack;
  }
  while (*haystack) {
    if (*haystack == *needle &&
        s21_strncmp(haystack, needle, needle_len) == 0) {
      return (char *)haystack;
    }
    haystack++;
  }
  return NULL;
}
