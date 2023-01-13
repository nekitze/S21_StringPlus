#ifndef SRC_S21_STRING_H
#define SRC_S21_STRING_H

#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define BUFF_SIZE 256

typedef struct format_struct {
  int minus;
  int plus;
  int space;
  int l;
  int h;
  int width;
  int precision;
  int isprecision;
  char spec;
} format_t;

int s21_sprintf(char *buf, const char *format, ...);
void copy_to_buf(char *buf, const char *string, va_list p_args);
void format_processing(const char *format, int *i, char *buf, va_list p_args);
void format_and_buff(int *i, char *buf, va_list p_args, format_t format_data);
void c_to_buf(const char, format_t format_data, char *buf, int *i);

#endif  // SRC_S21_STRING_H
