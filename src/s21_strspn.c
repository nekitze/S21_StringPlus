#include "s21_string.h"

size_t s21_strspn(const char *s, const char *accept) {
  const char *p;
  const char *a;
  size_t count = 0;

  for (p = s; *p != '\0'; p++) {
    for (a = accept; *a != '\0'; a++)
      if (*p == *a) break;
    if (*a == '\0')
      return count;
    else
      count++;
  }

  return count;
}
