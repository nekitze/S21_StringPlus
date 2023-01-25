#include "s21_string.h"

int s21_strncmp(const char *str1, const char *str2, size_t n) {
  int res = 0;
  while ((*str1 || *str2) && n--) {
    res = (unsigned char)*str1 - (unsigned char)*str2;
    if (res != 0) {
      break;
    }
    str1++;
    str2++;
  }
  return res;
}

char *s21_strncpy(char *dest, const char *src, size_t n) {
  if (dest != NULL) {
    for (size_t i = 0; i < n; i++) {
      dest[i] = src[i];
      if (src[i] == '\0') break;
    }
  }
  return dest;
}

size_t s21_strcspn(const char *str1, const char *str2) {
  int charactersNum = s21_strlen(str2), counter = 0, stopFlag = 0;
  while (*str1) {
    for (int i = 0; i < charactersNum; i++) {
      if (*str1 == str2[i]) stopFlag = 1;
    }
    if (stopFlag) break;
    counter++;
    str1++;
  }
  return counter;
}

char *s21_strrchr(const char *str, int c) {
  char *result = NULL;
  while (*str) {
    if (*str == c) {
      result = (char *)str;
    }
    str++;
  }
  return result;
}

int del_check(char c, const char *delim) {
  int res = 0;
  while (*delim != '\0') {
    if (c == *delim) res++;
    delim++;
  }
  return res;
}

char *s21_strerror(int errnum) {
  static char res[100] = {0};
  ARRAY;
  int flag = 0;
  for (int i = 0; i < ERR_MAX; i++) {
    if (errnum == i) {
      s21_strcpy(res, errlist[i]);
      flag = -1;
    }
  }
  if (flag == 0) {
    char str[100] = ERROR;
    char errnum_str[100];
    s21_itoa(errnum, errnum_str);
    char *tmp = s21_strcat(str, errnum_str);
    s21_strcpy(res, tmp);
  }
  return res;
}

char *s21_itoa(long int num, char *str) {
  long int fl = num < 0;
  int flag = 1;
  if (fl) {
    num *= -1;
  }
  s21_size_t i = 0;
  for (; flag; i++) {
    str[i] = num % 10 + 48;
    num /= 10;
    if (num == 0) {
      flag = 0;
    }
  }
  if (fl) {
    str[i++] = '-';
  }
  str[i] = 0;
  char tmp;
  for (s21_size_t j = 0; j < (s21_strlen(str)) / 2; j++) {
    tmp = str[j];
    str[j] = str[s21_strlen(str) - 1 - j];
    str[s21_strlen(str) - 1 - j] = tmp;
  }
  return str;
}