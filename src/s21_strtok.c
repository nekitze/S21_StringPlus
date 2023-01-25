#include "s21_string.h"

char *olds;

char *s21_strtok(char *str, const char *delim) {
  char *token = S21_NULL;
  if (str == S21_NULL) str = olds;

  /* Scan leading delimiters.  */
  str += s21_strspn(str, delim);  // handles possible trailing delims
  if (*str == '\0') {
    olds = str;
    return S21_NULL;
  }

  /* Find the end of the token.  */
  token = str;
  str = s21_strpbrk(token, delim);
  if (str == S21_NULL) {
    /* This token finishes the string.  */
    olds = s21_memchr(token, '\0', 1024);
  } else {
    /* Terminate the token and make OLDS point past it.  */
    *str = '\0';
    olds = str + 1;
  }
  return token;
}
