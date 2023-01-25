#include "s21_string.h"
// конвертирует входящий символ в число
int s21_atoi(const char *str_carriage) {
  int result = 0;
  int sign = 1;
  int overflow = 0;

  while (*str_carriage == ' ') str_carriage++;

  if (*str_carriage == '-') {
    str_carriage++;
    sign = -1;
  }

  if (*str_carriage == '+') {
    str_carriage++;
  }

  while (*str_carriage && *str_carriage >= '0' && *str_carriage <= '9') {
    result = result * 10 + (*str_carriage - '0');
    if (result < 0) {
      overflow = 1;
      break;
    }
    str_carriage++;
  }
  if (overflow)
    result = sign > 0 ? INT32_MAX : INT32_MIN;
  else
    result *= sign;

  return result;
}
