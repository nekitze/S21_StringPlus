#include "s21_string.h"

int s21_sscanf(const char *str, const char *format, ...) {
  int eof_happens = check_EOF_string(str), result = 0;

  if (!eof_happens) {
    va_list ap;  // arg pointer
    va_start(ap, format);

    char *str_carriage = (char *)str;
    char *format_carriage = (char *)format;
    int token_carriage = 0;
    int length = (int)s21_strlen(format_carriage);
    token tokens[BUFF_SIZE];

    for (int i = 0; i < length; i++) {
      tokens[token_carriage] = token_parse(&format_carriage, &ap);
      token_carriage++;
    }
    write_tokens_to_memory(&str_carriage, tokens, token_carriage, &result);
    va_end(ap);
  }
  return eof_happens == 1 ? eof_happens : result;
}

int space_check(char c) { return (c == ' ' || c == '\n' || c == '\t'); }

int register_check(char c) {
  return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

int check_EOF_string(const char *str_carriage) {
  int result = -1;

  for (int i = 0; str_carriage[i]; i++) {
    if (!space_check(str_carriage[i]) && str_carriage[i] != '\0') {
      result = 0;
      break;
    }
  }

  return result;
}

void skip_chars_in_buffer(char **src_carriage, int *fail, token *t) {
  skip_spaces_in_str(src_carriage);

  int test = s21_strspn(*src_carriage, t->buff);
  int length = s21_strlen(t->buff);

  if (test != length)
    *fail = 1;
  else
    (*src_carriage) = (*src_carriage) + length;
}

token token_parse(char **format, va_list *ap) {
  token t = {.address = S21_NULL,
             .token_length = NONE_LENGTH,
             .width = NONE_WIDTH,
             .spec = 0};

  if (space_check(**format)) {
    t.spec = ' ';  // тут пробел
    skip_spaces_in_str(format);
  }

  if (**format == '%' && !t.spec) {
    (*format)++;

    format_parse_width(format, &t);
    format_parse_length(format, &t);
    format_parse_specifier(format, &t);

    if (t.width != WIDTH_AST) t.address = va_arg(*ap, void *);

    if (t.spec == 'p') t.token_length = NONE_LENGTH;
  }

  if (register_check(**format) && !t.spec) {
    int i = 0;
    s21_memset(t.buff, '\0', 1024 - 1);
    while (**format && !space_check(**format) && **format != '%') {
      t.buff[i++] = **format;
      (*format)++;
    }
    t.spec = 'b';
  }
  return t;
}
//  result == 1
// Ширина перед спецификатором
void format_parse_width(char **format, token *t) {
  if (**format == '*') {
    (*format)++;
    t->width = WIDTH_AST;
  } else {
    int result = parse_number_from_format(format);

    if (result == 1) {
      t->width = WIDTH_NUMBER;
      t->width_status = result;
    }
  }
}

void format_parse_length(char **format, token *t) {
  switch (**format) {
    case 'h':
      t->token_length = LENGTH_SHORT;
      (*format)++;
      break;
    case 'l':
      t->token_length = LENGTH_LONG;
      (*format)++;
      if (**format == 'l') {
        t->token_length = LENGTH_LONG_LONG;
        (*format)++;
      }
      break;
    case 'L':
      t->token_length = LENGTH_LONG_DOUBLE;
      (*format)++;
      break;
  }
}

void format_parse_specifier(char **format, token *t) {
  t->spec = (**format);
  (*format)++;
}

void write_tokens_to_memory(char **str_carriage, token *t, int token_carriage,
                            int *result) {
  char *start_position = *str_carriage;

  for (int i = 0, fail_flag = 0; i < token_carriage && !fail_flag; i++) {
    char spec = t[i].spec;
    if (spec == 'c') write_char_to_memory(str_carriage, result, (t + i));
    if (spec == 'd')
      write_int_to_memory(str_carriage, &fail_flag, result, (t + i));
    if (spec == 'i')
      write_unspec_int_to_memory(str_carriage, &fail_flag, result, (t + i));
    if (spec == 'f' || spec == 'g' || spec == 'G')
      write_float_to_memory(str_carriage, result, (t + i));
    if (spec == 'o')
      write_8_16_to_memory(str_carriage, &fail_flag, result, (t + i), 8);
    if (spec == 's')
      write_string_to_memory(str_carriage, &fail_flag, result, (t + i));
    if (spec == 'u')
      write_unsigned_to_memory(str_carriage, &fail_flag, result, (t + i));
    if (spec == 'x' || spec == 'X' || spec == 'p')
      write_8_16_to_memory(str_carriage, &fail_flag, result, (t + i), 16);
    if (spec == 'n') *((int *)t[i].address) = (*str_carriage) - start_position;
    if (spec == ' ') skip_spaces_in_str(str_carriage);
    if (spec == 'b') skip_chars_in_buffer(str_carriage, &fail_flag, (t + i));
  }
}

int parse_number_from_format(char **format) {
  char tmp[BUFF_SIZE] = {'\0'};
  int result = 0, i = 0;

  // если это цифра, то добавляет ее в конец массива tmp
  while (**format >= '0' && **format <= '9') {
    tmp[i] = **format;
    (*format)++;
    i++;
  }
  result = s21_atoi(tmp);
  return result;
}

void write_chars_to_buff(char **str_carriage, const char *c, char *buff,
                         int16_t width, int start_ind) {
  while (**str_carriage && s21_strspn(*str_carriage, c) != 0) {
    if ((width && start_ind >= width) || (space_check(**str_carriage))) break;

    if (buff) buff[start_ind] = **str_carriage;

    (*str_carriage)++;
    start_ind++;
  }
}

void write_char_to_memory(char **str_carriage, int *result, token *t) {
  if (t->width == WIDTH_AST) {
    (*str_carriage)++;
  } else {
    *(char *)t->address = **str_carriage;
    (*str_carriage)++;
    (*result)++;
  }
}
// Имеются приколы с принятием ++/--
void write_int_to_memory(char **str_carriage, int *fail_flag, int *res,
                         token *t) {
  long long int result = 0;
  char buff[BUFF_SIZE] = {'\0'};
  *fail_flag = 1;

  if (s21_strspn(*str_carriage, "0123456789+-")) {
    int sign = s21_strspn(*str_carriage, "+-");

    if (!(sign > 1 || (sign && (t->width_status <= 1 && t->width)))) {
      buff[0] = **str_carriage;
      (*str_carriage)++;
      write_chars_to_buff(str_carriage, "0123456789", buff, t->width_status, 1);
      if (t->width != WIDTH_AST) (*res)++;
      *fail_flag = 0;
    }
  }
  result = s21_atoi(buff);

  if (t->width != WIDTH_AST && !*fail_flag) int_type_converter(t, result, 1);

  if (t->width != WIDTH_NUMBER)
    write_chars_to_buff(str_carriage, "0123456789", S21_NULL, 0, 0);
}

void write_float_to_memory(char **str_carriage, int *result, token *t) {
  int test = 0;

  if (t->spec == 'f')
    test = s21_strspn(*str_carriage, "0123456789+-");
  else
    test = s21_strspn(*str_carriage, "0123456789eE+-NnaAifIF");

  if (test) {
    int sign = s21_strspn(*str_carriage, "+-");
    if (!(sign > 1 || (sign && (t->width_status <= 1 && t->width)))) {
      char buff[BUFF_SIZE] = {'\0'};
      int start_index = 0;
      if (sign) {
        buff[0] = **str_carriage;
        start_index = 1;
        (*str_carriage)++;
      }
      if (t->spec == 'f')
        write_chars_to_buff(str_carriage, ".0123456789+-", buff,
                            t->width_status, start_index);
      else
        write_chars_to_buff(str_carriage, ".0123456789eE+-NnaAifIF", buff,
                            t->width_status, start_index);
      if (t->width != WIDTH_AST) {
        // конвертируем строку в double
        long double result_strtold = s21_strtold(buff, NULL);
        (*result)++;
        float_type_converter(t, result_strtold);
      }
    }
  }

  if (t->width != WIDTH_NUMBER) {
    if (t->spec == 'f')
      write_chars_to_buff(str_carriage, ".0123456789", S21_NULL, 0, 0);
    else
      write_chars_to_buff(str_carriage, ".0123456789eE+-NaAifIFn", S21_NULL, 0,
                          0);
  }
}

void write_string_to_memory(char **str_carriage, const int *fail_flag,
                            int *result, token *t) {
  int success = 0;
  char buff[BUFF_SIZE] = {'\0'};
  unsigned int i = 0;

  while (**str_carriage != '\0' && !success && !(*fail_flag)) {
    if (!space_check(**str_carriage)) {
      success = 1;
      while (**str_carriage != '\0' && !(*fail_flag)) {
        buff[i] = **str_carriage;
        i++;

        if (t->width == WIDTH_NUMBER && i >= t->width_status) {
          break;
        }
        (*str_carriage)++;

        if (space_check(**str_carriage)) {
          (*str_carriage)--;
          break;
        }
      }
    }

    (*str_carriage)++;
  }

  if (t->width != WIDTH_AST && success) {
    s21_strcpy((char *)t->address, buff);
    (*result)++;
  }
}

void write_unspec_int_to_memory(char **str_carriage, int *fail_flag,
                                int *result, token *t) {
  *fail_flag = 1;
  skip_spaces_in_str(str_carriage);

  if (s21_strspn(*str_carriage, "+-0123456789")) {
    *fail_flag = 0;
    write_int_to_memory(str_carriage, fail_flag, result, t);
  } else if (s21_strspn(*str_carriage, "0") == 1) {
    *fail_flag = 0;
    write_8_16_to_memory(str_carriage, fail_flag, result, t, 8);
  } else if (s21_strspn(*str_carriage, "0x") == 2) {
    *fail_flag = 0;
    write_8_16_to_memory(str_carriage, fail_flag, result, t, 16);
  }
}

void write_unsigned_to_memory(char **str_carriage, int *fail_flag, int *result,
                              token *t) {
  *fail_flag = 1;
  skip_spaces_in_str(str_carriage);
  char buff[BUFF_SIZE] = {'\0'};

  if (s21_strspn(*str_carriage, "0123456789+-")) {
    int sign = s21_strspn(*str_carriage, "+-");
    if (!((sign > 1 || (sign && (t->width_status <= 1 && t->width))))) {
      *fail_flag = 0;
      buff[0] = **str_carriage;
      (*str_carriage)++;

      write_chars_to_buff(str_carriage, "0123456789", buff, t->width_status, 1);

      if (t->width != WIDTH_AST) (*result)++;
    }
  }
  unsigned long long int result_atoi = s21_atoi(buff);

  if (t->width != WIDTH_AST && !*fail_flag)
    unsigned_type_converter(t, result_atoi, 1);

  if (t->width != WIDTH_NUMBER)
    write_chars_to_buff(str_carriage, "0123456789", S21_NULL, 0, 0);
}
// stroll
void write_8_16_to_memory(char **str_carriage, int *fail_flag, int *result,
                          token *t, int base) {
  char *null_pointer = S21_NULL;
  int sign = 1;

  skip_spaces_in_str(str_carriage);

  if (**str_carriage == '-') {
    t->width_status--;
    sign = -1;
    (*str_carriage)++;
  }
  if (s21_strspn(*str_carriage, "0123456789abcdefABCDEF") > 0 ||
      s21_strspn(*str_carriage, "xX0123456789abcdefABCDEF") >= 2) {
    unsigned long long int res =
        s21_strntollu(*str_carriage, &null_pointer, base,
                      t->width ? t->width_status : s21_strlen(*str_carriage));
    if (t->width != WIDTH_AST) {
      if (t->spec == 'p')
        *(int *)t->address = (int)res;
      else
        unsigned_type_converter(t, res, sign);
      *result += 1;
    } else {
      s21_strntollu(*str_carriage, &null_pointer, base,
                    t->width ? t->width_status : s21_strlen(*str_carriage));
    }
  } else {
    *fail_flag = 1;
  }
  *str_carriage = null_pointer;
}

void skip_spaces_in_str(char **str_carriage) {
  while (**str_carriage && space_check(**str_carriage)) {
    (*str_carriage)++;
  }
}

void unsigned_type_converter(token *t, unsigned long long int result,
                             int sign) {
  if (t->token_length == NONE_LENGTH) {
    *(unsigned int *)t->address = sign * (unsigned int)result;
  } else if (t->token_length == LENGTH_SHORT) {
    *(unsigned short int *)t->address = sign * (unsigned short int)result;
  } else if (t->token_length == LENGTH_LONG) {
    *(unsigned long int *)t->address = sign * (unsigned long int)result;
  } else if (t->token_length == LENGTH_LONG_LONG) {
    *(unsigned long long int *)t->address =
        sign * (unsigned long long int)result;
  }
}

void int_type_converter(token *t, long long int result, int sign) {
  if (t->token_length == NONE_LENGTH) {
    *(int *)t->address = sign * (int)result;
  } else if (t->token_length == LENGTH_SHORT) {
    *(short int *)t->address = sign * (short int)result;
  } else if (t->token_length == LENGTH_LONG) {
    *(long int *)t->address = sign * (long int)result;
  } else if (t->token_length == LENGTH_LONG_LONG) {
    *(long long int *)t->address = sign * (long long int)result;
  }
}

void float_type_converter(token *t, long double result) {
  if (t->token_length == NONE_LENGTH) *(float *)t->address = (float)result;
  if (t->token_length == LENGTH_LONG) *(double *)t->address = (double)result;
  if (t->token_length == LENGTH_LONG_DOUBLE)
    *(long double *)t->address = (long double)result;
}
