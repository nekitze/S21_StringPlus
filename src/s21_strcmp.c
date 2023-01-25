#include "s21_string.h"

int s21_strcmp(const char *str1, const char *str2) {
  int i = 0;
  int res = 0;
  while ((str1[i] == str2[i]) && (str1[i] != '\0') && (str2[i] != '\0')) {
    i++;
  }
  res = ((unsigned char)str1[i] - (unsigned char)str2[i]);
  return res;
}
