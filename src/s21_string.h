#ifndef SRC_S21_STRING_H
#define SRC_S21_STRING_H

#include <stdarg.h>
#include <string.h>
#include <stdint.h>
#include <math.h>

#define BUFF_SIZE 512

typedef struct format_struct {
  int minus;
  int plus;
  int space;
  char length;
  int width;
  int zero;
  int prec;
  int isprec;
  char spec;
} format_t;

typedef union {
  float f;
  struct {
    unsigned int mantisa : 23;
    unsigned int exponent : 8;
    unsigned int sign : 1;
  } parts;
} float_cast;

int s21_sprintf(char *buf, const char *format, ...);
void copy_to_buf(char *buf, const char *string, va_list p_args);
void format_processing(const char *format, int *i, char *buf, va_list p_args);
void format_and_buff(int *i, char *buf, va_list p_args, format_t format_data);
void c_to_buf(const char c, format_t format_data, char *buf, int *i);
void d_to_buf(int64_t d, format_t format_data, char *buf, int *i);
void format_flag(char *temp, format_t format_data, char *buf, int *i, int mode);
void f_to_buf(long double f, format_t params, char *buf, int *i);

#endif  // SRC_S21_STRING_H
