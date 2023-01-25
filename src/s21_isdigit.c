#include "s21_string.h"

int s21_isdigit(char c) {
  if (c >= '0' && c <= '9') {
    return 1;
  }
  return 0;
}