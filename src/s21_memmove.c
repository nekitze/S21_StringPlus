#include "s21_string.h"

void *s21_memmove(void *dest, const void *src, s21_size_t n) {
  unsigned char *dest_p = (unsigned char *)dest;
  const unsigned char *src_p = (const unsigned char *)src;
  if (dest_p < src_p) {
    while (n--) *dest_p++ = *src_p++;
  } else {
    dest_p += n - 1;
    src_p += n - 1;
    while (n--) *dest_p-- = *src_p--;
  }
  return dest;
}
