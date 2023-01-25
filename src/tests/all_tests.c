#include <check.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <wchar.h>

#include "../s21_string.h"

#define NMAX 1024
#define AMOUNT 10

// %[flags][width][.precision][length]specifier

START_TEST(test_default) {
  char result[20];
  char assert[20];
  s21_sprintf(result, "Count: %c", 'a');
  sprintf(assert, "Count: %c", 'a');
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default2) {
  char result[20];
  char assert[20];
  char c = 'b';
  s21_sprintf(result, "Count: %c", c);
  sprintf(assert, "Count: %c", c);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default3) {
  char result[20];
  char assert[20];
  char c = 'b';
  int a = s21_sprintf(result, "Count: %5c", c);
  int b = sprintf(assert, "Count: %5c", c);
  ck_assert_str_eq(result, assert);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(test_default4) {
  char result[20];
  char assert[20];
  char c = 'b';
  int a = s21_sprintf(result, "Count: %-5c", c);
  int b = sprintf(assert, "Count: %-5c", c);
  ck_assert_str_eq(result, assert);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(test_default5) {
  char result[20] = {'\0'};
  char assert[20] = {'\0'};
  char c = 'z';
  s21_sprintf(result, "Count: %lc", c);
  sprintf(assert, "Count: %lc", c);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default6) {
  char result[20];
  char assert[20];
  char c = 'a';
  s21_sprintf(result, "Count: %-3c", c);
  sprintf(assert, "Count: %-3c", c);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default7) {  // need to fix '*'
  char result[20];
  char assert[20];
  char c = 'a';
  s21_sprintf(result, "Count: %*c", 4, c);
  sprintf(assert, "Count: %*c", 4, c);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default8) {
  char result[20];
  char assert[20];
  long long d = 5717984;
  s21_sprintf(result, "Count: %Li 1", d);
  sprintf(assert, "Count: %Li 1", d);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default10) {
  char result[20];
  char assert[20];
  int d = 57;
  s21_sprintf(result, "Count: %d abc", d);
  sprintf(assert, "Count: %d abc", d);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default9) {
  char result[20];
  char assert[20];
  int d = 190;
  s21_sprintf(result, "Count: %5d", d);
  sprintf(assert, "Count: %5d", d);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default_multy) {
  char result[20];
  char assert[20];
  s21_sprintf(result, "Count: %d%d%d%d", -4, 8, 15, 16);
  sprintf(assert, "Count: %d%d%d%d", -4, 8, 15, 16);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_format_d) {
  char result[20];
  char assert[20];
  s21_sprintf(result, "Count: %1.1d", 69);
  sprintf(assert, "Count: %1.1d", 69);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_no_args) {
  char result[20];
  char assert[20];
  s21_sprintf(result, "Hello, world!");
  sprintf(assert, "Hello, world!");
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_flag_minus) {  // TO FIX
  char result[20];
  char assert[20];
  s21_sprintf(result, "Count: %-5d", 69);
  sprintf(assert, "Count: %-5d", 69);
  ck_assert_str_eq(result, assert);
}
END_TEST

// START_TEST(str_to_int_test) {
//     char s[10] = "123\0";
//     int result = str_to_int(s);
//     ck_assert_int_eq(result, 123);
// }
// END_TEST

START_TEST(test_char_default) {
  char c = 'B';
  char result[20];
  char assert[20];
  s21_sprintf(result, "Char: %c", c);
  sprintf(assert, "Char: %c", c);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_char_multy) {
  char c = 'B';
  char result[20];
  char assert[20];
  s21_sprintf(result, "Char: %c%c%c", c, c, c);
  sprintf(assert, "Char: %c%c%c", c, c, c);
  ck_assert_str_eq(result, assert);
}
END_TEST

// START_TEST(test_buffer_overflow) {
//     char result[20];
//     char assert[20];
//     s21_sprintf(result, "%d", 3000000000);
//     sprintf(assert, "%d", 3000000000);
//     ck_assert_str_eq(result, assert);
// }
// END_TEST

START_TEST(test_default11) {
  char result[20];
  char assert[20];
  int d = 571212;
  s21_sprintf(result, "Count: %.5d abc", d);
  sprintf(assert, "Count: %.5d abc", d);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default12) {
  char result[20];
  char assert[20];
  int d = 5312112;
  s21_sprintf(result, "Count: %-.5d abc", d);
  sprintf(assert, "Count: %-.5d abc", d);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default13) {
  char result[20];
  char assert[20];
  int d = 0;
  s21_sprintf(result, "Count: %d abc", d);
  sprintf(assert, "Count: %d abc", d);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default14) {
  char result[20];
  char assert[20];
  int d = 0;
  s21_sprintf(result, "Count: %d abc", d);
  sprintf(assert, "Count: %d abc", d);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default15) {
  char result[20];
  char assert[20];
  int d = 1;
  s21_sprintf(result, "Count: % d abc", d);
  sprintf(assert, "Count: % d abc", d);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default16) {
  char result[20];
  char assert[20];
  int d = -1;
  s21_sprintf(result, "Count: % d abc", d);
  sprintf(assert, "Count: % d abc", d);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default17) {
  char result[20];
  char assert[20];
  int d = -0;
  s21_sprintf(result, "Count: % d abc", d);
  sprintf(assert, "Count: % d abc", d);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default18) {
  char result[40];
  char assert[40];
  int d = 2147483647;
  s21_sprintf(result, "Count: % d abc", d);
  sprintf(assert, "Count: % d abc", d);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default19) {
  char result[40];
  char assert[40];
  int d = -2147483648;
  s21_sprintf(result, "Count: % d abc", d);
  sprintf(assert, "Count: % d abc", d);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default20) {
  char result[40];
  char assert[40];
  long int d = 214748364912;
  s21_sprintf(result, "Count: % ld abc", d);
  sprintf(assert, "Count: % ld abc", d);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default21) {
  char result[40];
  char assert[40];
  long int d = -9223372036854775807;
  s21_sprintf(result, "Count: % ld abc", d);
  sprintf(assert, "Count: % ld abc", d);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default22) {
  char result[40];
  char assert[40];
  long int d = 9223372036854775807;
  s21_sprintf(result, "Count: %ld abc", d);
  sprintf(assert, "Count: %ld abc", d);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default23) {
  char result[40];
  char assert[40];
  short int d = 32767;
  s21_sprintf(result, "Count: %hd abc", d);
  sprintf(assert, "Count: %hd abc", d);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default24) {
  char result[40];
  char assert[40];
  short int d = 32770;
  s21_sprintf(result, "Count: %hd end", d);
  sprintf(assert, "Count: %hd end", d);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default25) {
  char result[40];
  char assert[40];
  int d = 327710;
  s21_sprintf(result, "Count: %11.10d end", d);
  sprintf(assert, "Count: %11.10d end", d);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default26) {
  char result[20];
  char assert[20];
  int i = 57;
  s21_sprintf(result, "Count: %i 1", i);
  sprintf(assert, "Count: %i 1", i);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default27) {
  char result[20];
  char assert[20];
  int i = 57;
  s21_sprintf(result, "Count: %i abc", i);
  sprintf(assert, "Count: %i abc", i);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default28) {
  char result[20];
  char assert[20];
  int i = 190;
  s21_sprintf(result, "Count: %5i", i);
  sprintf(assert, "Count: %5i", i);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default29) {
  char result[20];
  char assert[20];
  s21_sprintf(result, "Count: %i%i%i%i", -4, 8, 15, 16);
  sprintf(assert, "Count: %i%i%i%i", -4, 8, 15, 16);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default30) {
  char result[20];
  char assert[20];
  s21_sprintf(result, "Count: %1.1i", 69);
  sprintf(assert, "Count: %1.1i", 69);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default31) {
  char result[20];
  char assert[20];
  int i = 571212;
  s21_sprintf(result, "Count: %.5i abc", i);
  sprintf(assert, "Count: %.5i abc", i);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default32) {
  char result[20];
  char assert[20];
  int i = 5312112;
  s21_sprintf(result, "Count: %-.5i abc", i);
  sprintf(assert, "Count: %-.5i abc", i);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default33) {
  char result[20];
  char assert[20];
  int i = 0;
  s21_sprintf(result, "Count: %i abc", i);
  sprintf(assert, "Count: %i abc", i);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default34) {
  char result[20];
  char assert[20];
  int i = 0;
  s21_sprintf(result, "Count: %i abc", i);
  sprintf(assert, "Count: %i abc", i);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default35) {
  char result[20];
  char assert[20];
  int i = 1;
  s21_sprintf(result, "Count: % i abc", i);
  sprintf(assert, "Count: % i abc", i);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default36) {
  char result[20];
  char assert[20];
  int i = -1;
  s21_sprintf(result, "Count: % i abc", i);
  sprintf(assert, "Count: % i abc", i);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default37) {
  char result[20];
  char assert[20];
  int i = -0;
  s21_sprintf(result, "Count: % i abc", i);
  sprintf(assert, "Count: % i abc", i);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default38) {
  char result[40];
  char assert[40];
  int i = 2147483647;
  s21_sprintf(result, "Count: % i abc", i);
  sprintf(assert, "Count: % i abc", i);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default39) {
  char result[40];
  char assert[40];
  int i = -2147483648;
  s21_sprintf(result, "Count: % i abc", i);
  sprintf(assert, "Count: % i abc", i);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default40) {
  char result[40];
  char assert[40];
  long int i = 214748364912;
  s21_sprintf(result, "Count: % li abc", i);
  sprintf(assert, "Count: % li abc", i);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default41) {
  char result[40];
  char assert[40];
  long int i = -9223372036854775807;
  s21_sprintf(result, "Count: % li abc", i);
  sprintf(assert, "Count: % li abc", i);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default42) {
  char result[40];
  char assert[40];
  long int i = 9223372036854775807;
  s21_sprintf(result, "Count: %li abc", i);
  sprintf(assert, "Count: %li abc", i);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default43) {
  char result[40];
  char assert[40];
  short int i = 32767;
  s21_sprintf(result, "Count: %hi abc", i);
  sprintf(assert, "Count: %hi abc", i);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default44) {
  char result[40];
  char assert[40];
  short int i = 32770;
  s21_sprintf(result, "Count: %hi end", i);
  sprintf(assert, "Count: %hi end", i);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default45) {
  char result[40];
  char assert[40];
  int i = 327710;
  s21_sprintf(result, "Count: %5.10i end", i);
  sprintf(assert, "Count: %5.10i end", i);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default46) {
  char result[40];
  char assert[40];
  int i = 327710;
  s21_sprintf(result, "Count: %-+10.5i end", i);
  sprintf(assert, "Count: %-+10.5i end", i);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default47) {
  char result[40];
  char assert[40];
  int i = 327710;
  s21_sprintf(result, "Count: %+10.5i end", i + 1);
  sprintf(assert, "Count: %+10.5i end", i + 1);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default48) {
  char result[40];
  char assert[40];
  float f = -14.537;
  s21_sprintf(result, "Count: %.6f end", f);
  sprintf(assert, "Count: %.6f end", f);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default49) {
  char result[40];
  char assert[40];
  float f = 14.537;
  s21_sprintf(result, "Count: %2.2f end", f);
  sprintf(assert, "Count: %2.2f end", f);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default50) {
  char result[40];
  char assert[40];
  float f = 1.0010021;
  s21_sprintf(result, "Count: %f end", f);
  sprintf(assert, "Count: %f end", f);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default51) {
  char result[40];
  char assert[40];
  float f = 0;
  s21_sprintf(result, "Count: %f end", f);
  sprintf(assert, "Count: %f end", f);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default52) {
  char result[40];
  char assert[40];
  float f = 0.;
  s21_sprintf(result, "Count: %f end", f);
  sprintf(assert, "Count: %f end", f);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default53) {
  char result[40];
  char assert[40];
  float f = -123.321;
  s21_sprintf(result, "Count: %f end", f);
  sprintf(assert, "Count: %f end", f);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default54) {
  char result[40];
  char assert[40];
  float f = 1.1234;
  s21_sprintf(result, "Count: %.*f end", 3, f);
  sprintf(assert, "Count: %.*f end", 3, f);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default55) {
  char result[40];
  char assert[40];
  float f = -.0000001;
  s21_sprintf(result, "Count: %f end", f);
  sprintf(assert, "Count: %f end", f);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default56) {
  char result[40];
  char assert[40];
  float f = -.0000001;
  s21_sprintf(result, "Count: %10f end", f);
  sprintf(assert, "Count: %10f end", f);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default57) {
  char result[40];
  char assert[40];
  double f = -.0000001;
  s21_sprintf(result, "Count: %3.5lf end", f);
  sprintf(assert, "Count: %3.5lf end", f);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(float_precision) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%Lf";
  long double val = 513515.131513515151351;
  int a = s21_sprintf(str1, format, val);
  int b = sprintf(str2, format, val);

  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(a, b);
}
END_TEST
START_TEST(float_width) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%10Lf";
  long double val = 15.35;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(float_precision_zero) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%.0Lf";
  long double val = 15.35;
  s21_sprintf(str1, format, val);
  sprintf(str2, format, val);

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(float_precision_empty) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%.Lf";
  long double val = 15.35;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(float_precision_huge) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%.15Lf";
  long double val = 15.35;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(float_precision_huge_negative) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%.15Lf";
  long double val = -15.35581134;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(float_huge) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%Lf";
  long double val = 72537572375.1431341;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(float_flags) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "% f";
  float val = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(float_many) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "% .0f %.lf %Lf %f %lf %Lf";
  float val = 0;
  double val1 = 0;
  long double val2 = 3515315.153151;
  float val3 = 5.5;
  double val4 = 9851.51351;
  long double val5 = 95919539159.53151351131;
  ck_assert_int_eq(s21_sprintf(str1, format, val, val1, val2, val3, val4, val5),
                   sprintf(str2, format, val, val1, val2, val3, val4, val5));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_one_float) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%f", 0.0001),
                   sprintf(str2, "%f", 0.0001));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_many_float) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(
      s21_sprintf(str1, "%f%f%f%f", -999.666, 0.0001, 666.999, -100.001),
      sprintf(str2, "%f%f%f%f", -999.666, 0.0001, 666.999, -100.001));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_default58) {
  char result[40];
  char assert[40];
  float f = 14.537;
  s21_sprintf(result, "%+0.2f", f);
  sprintf(assert, "%+0.2f", f);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default59) {
  char result[40];
  char assert[40];
  char *s = "none";
  s21_sprintf(result, "Count: %s abc", s);
  sprintf(assert, "Count: %s abc", s);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default60) {
  char result[40];
  char assert[40];
  char *s = "none";
  s21_sprintf(result, "Count: %.3s abc", s);
  sprintf(assert, "Count: %.3s abc", s);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default61) {
  char result[40];
  char assert[40];
  char *s = "none";
  s21_sprintf(result, "%.6s", s);
  sprintf(assert, "%.6s", s);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default62) {
  char result[40];
  char assert[40];
  char *s = "stroka s probelom";
  s21_sprintf(result, "%5.6s", s);
  sprintf(assert, "%5.6s", s);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default63) {
  char result[40];
  char assert[40];
  char *s = "stroka s probelom";
  s21_sprintf(result, "%-5.6s", s);
  sprintf(assert, "%-5.6s", s);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default64) {
  char result[40];
  char assert[40];
  wchar_t s[] = L"wide chars: ";
  s21_sprintf(result, "%-5.6ls", s);
  sprintf(assert, "%-5.6ls", s);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(string) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%s";
  char *val = "21R DSADA SDHASDOAMDSA sdas8d7nasd 111";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(string_precision) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%.15s";
  char *val = "21R DSADA SDHASDOAMDSA sdas8d7nasd 111";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(string_width) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%15s";
  char *val = "21R DSADA SDHASDOAMDSA sdas8d7nasd 111";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(string_flags) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%-15.9s";
  char *val = "21R DSADA SDHASDOAMDSA sdas8d7nasd 111";
  s21_sprintf(str1, format, val), sprintf(str2, format, val);

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(string_long) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%s";
  char *val = "ADibsy8 ndASN) dun8AWn dA 9sDNsa NAID saDYBU DSnaJ Sd";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(string_many) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%s%s%s%s";
  char *val = "ADibsy8 ndASN) dun8AWn dA 9sDNsa NAID saDYBU DSnaJ Sd";
  char *s1 = "";
  char *s2 = "87418347813748913749871389480913";
  char *s3 = "HAHAABOBASUCKER";
  ck_assert_int_eq(s21_sprintf(str1, format, val, s1, s2, s3),
                   sprintf(str2, format, val, s1, s2, s3));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(string_width_huge) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *val = "kjafdiuhfjahfjdahf";
  char *format = "%120s";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_one_string) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%s", "DASdw D sadw ASD"),
                   sprintf(str2, "%s", "DASdw D sadw ASD"));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_many_string) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(
      s21_sprintf(str1, "%s%s%s%s%s", "DASdw", " ", "sadw", " ", "ASD"),
      sprintf(str2, "%s%s%s%s%s", "DASdw", " ", "sadw", " ", "ASD"));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(wstr) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "wchar: %ls";
  wchar_t w[] = L"à";
  int a = s21_sprintf(str1, format, w);
  int b = sprintf(str2, format, w);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(wstr1) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "wchar: %5.12ls";
  wchar_t w[] = L"àààààà";
  int a = s21_sprintf(str1, format, w);
  int b = sprintf(str2, format, w);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(wstr2) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "wchar: %120hs ABOBA";
  wchar_t w[] = L"森我爱菠萝";
  int a = s21_sprintf(str1, format, w);
  int b = sprintf(str2, format, w);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(a, b);
}
END_TEST
START_TEST(wstr3) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%-43ls";
  wchar_t w[] = L"森我爱菠萝";
  int a = s21_sprintf(str1, format, w);
  int b = sprintf(str2, format, w);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(a, b);
}
END_TEST
START_TEST(wstr4) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "wchar: %43ls";
  wchar_t w[] = L"森我爱菠萝";
  int a = s21_sprintf(str1, format, w);
  int b = sprintf(str2, format, w);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(a, b);
}
END_TEST
START_TEST(wchr2) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "wchar: %43lc 123";
  wchar_t w = L'B';
  // int a = s21_sprintf(str1, format, w);
  // int b =sprintf(str2, format, w);
  s21_sprintf(str1, format, w);
  sprintf(str2, format, w);
  // ck_assert_int_eq(a, b);
  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(wchr) {
  char str1[BUFF_SIZE] = {'\0'};
  char str2[BUFF_SIZE] = {'\0'};

  char *format = "wchar: %lc";
  wchar_t w = L'1';
  int a = s21_sprintf(str1, format, w);
  int b = sprintf(str2, format, w);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(width_char) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "wchar: %5c";
  char w = 'c';
  int a = s21_sprintf(str1, format, w);
  int b = sprintf(str2, format, w);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(a, b);
}
START_TEST(minus_wchr) {
  char str1[BUFF_SIZE] = {'\0'};
  char str2[BUFF_SIZE] = {'\0'};

  char *format = "wchar: %-5lc";
  unsigned long w = L'~';
  int a = s21_sprintf(str1, format, w);
  int b = sprintf(str2, format, w);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(test_default65) {
  char result[20];
  char assert[20];
  unsigned int u = 571212;
  s21_sprintf(result, "Count: %.5u abc", u);
  sprintf(assert, "Count: %.5u abc", u);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default66) {
  char result[20];
  char assert[20];
  unsigned int u = 5312112;
  s21_sprintf(result, "Count: %-.5u abc", u);
  sprintf(assert, "Count: %-.5u abc", u);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default67) {
  char result[20];
  char assert[20];
  unsigned int u = 0;
  s21_sprintf(result, "Count: %u abc", u);
  sprintf(assert, "Count: %u abc", u);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default68) {
  char result[20];
  char assert[20];
  unsigned int u = 0;
  s21_sprintf(result, "Count: %u abc", u);
  sprintf(assert, "Count: %u abc", u);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default69) {
  char result[20];
  char assert[20];
  unsigned int u = 1;
  s21_sprintf(result, "Count: %u abc", u);
  sprintf(assert, "Count: %u abc", u);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default70) {
  char result[20];
  char assert[20];
  unsigned int u = 1;
  s21_sprintf(result, "Count: %u abc", u);
  sprintf(assert, "Count: %u abc", u);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default71) {
  char result[20];
  char assert[20];
  unsigned int u = -0;
  s21_sprintf(result, "Count: %u abc", u);
  sprintf(assert, "Count: %u abc", u);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default72) {
  char result[40];
  char assert[40];
  unsigned int u = 2147483647;
  s21_sprintf(result, "Count: %u abc", u);
  sprintf(assert, "Count: %u abc", u);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default73) {
  char result[40];
  char assert[40];
  unsigned int u = -2147483648;
  s21_sprintf(result, "Count: %u abc", u);
  sprintf(assert, "Count: %u abc", u);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default74) {
  char result[40];
  char assert[40];
  unsigned long int u = 214748364912;
  s21_sprintf(result, "Count: %lu abc", u);
  sprintf(assert, "Count: %lu abc", u);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default75) {
  char result[40];
  char assert[40];
  unsigned long int u = -9223372036854775807;
  s21_sprintf(result, "Count: %lu abc", u);
  sprintf(assert, "Count: %lu abc", u);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default76) {
  char result[40];
  char assert[40];
  unsigned long int u = 9223372036854775807;
  s21_sprintf(result, "Count: %lu abc", u);
  sprintf(assert, "Count: %lu abc", u);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default77) {
  char result[40];
  char assert[40];
  unsigned short int u = 32767;
  s21_sprintf(result, "Count: %hu abc", u);
  sprintf(assert, "Count: %hu abc", u);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default78) {
  char result[40];
  char assert[40];
  unsigned short int u = 32770;
  s21_sprintf(result, "Count: %hu end", u);
  sprintf(assert, "Count: %hu end", u);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default79) {
  char result[40];
  char assert[40];
  unsigned int u = 327710;
  s21_sprintf(result, "Count: %11.10u end", u);
  sprintf(assert, "Count: %11.10u end", u);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default80) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%g";
  double hex = 0.50300;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_default81) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%g";
  double hex = 5131.43;
  s21_sprintf(str1, format, hex);
  sprintf(str2, format, hex);

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_default82) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%g";
  double hex = 0.1;
  s21_sprintf(str1, format, hex);
  sprintf(str2, format, hex);

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_default83) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%.5g";
  double hex = 0.55555;
  s21_sprintf(str1, format, hex);
  sprintf(str2, format, hex);

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_default84) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%.0g";
  double hex = 0.4;
  s21_sprintf(str1, format, hex);
  sprintf(str2, format, hex);

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_default85) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%.g";
  double hex = 5;
  s21_sprintf(str1, format, hex);
  sprintf(str2, format, hex);

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_default86) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%.g";
  double hex = 0.0004;
  s21_sprintf(str1, format, hex);
  sprintf(str2, format, hex);

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_default87) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%g";
  double hex = 0;
  s21_sprintf(str1, format, hex);
  sprintf(str2, format, hex);

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_default88) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%.5g";
  double hex = 0;
  s21_sprintf(str1, format, hex);
  sprintf(str2, format, hex);

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_default89) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%5g";
  double hex = 0.0000005;
  s21_sprintf(str1, format, hex);
  sprintf(str2, format, hex);

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_default90) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%5.8g";
  double hex = 0.0000005;
  s21_sprintf(str1, format, hex);
  sprintf(str2, format, hex);

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_default91) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%g";
  double hex = 0.005;
  s21_sprintf(str1, format, hex);
  sprintf(str2, format, hex);

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_default92) {
  char str1[BUFF_SIZE] = {'\0'};
  char str2[BUFF_SIZE] = {'\0'};
  char format[] = "%LG";
  long double hex = 0.000005;
  s21_sprintf(str1, format, hex);
  sprintf(str2, format, hex);

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_default93) {
  char str1[BUFF_SIZE] = {'\0'};
  char str2[BUFF_SIZE] = {'\0'};
  char format[] = "%LG %g %G %Lg %.5g";
  long double hex = 0.000005;
  double hex1 = 41.1341;
  double hex2 = 848.9000;
  long double hex3 = 0.0843;
  double hex4 = 0.0005;
  double hex5 = 0.8481481;
  s21_sprintf(str1, format, hex, hex1, hex2, hex3, hex4, hex5);
  sprintf(str2, format, hex, hex1, hex2, hex3, hex4, hex5);

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_default94) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%.17Le";
  long double val = 15.35;
  s21_sprintf(str1, format, val);
  sprintf(str2, format, val);

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_default95) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%.0Le";
  long double val = 15.35;
  s21_sprintf(str1, format, val);
  sprintf(str2, format, val);

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_default96) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%.Le";
  long double val = 15.000009121;
  s21_sprintf(str1, format, val);
  sprintf(str2, format, val);

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_default97) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%.15Le";
  long double val = 0.000000000000000123;
  s21_sprintf(str1, format, val);
  sprintf(str2, format, val);

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_default98) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%.15Le";
  long double val = -15.35581134;
  s21_sprintf(str1, format, val);
  sprintf(str2, format, val);

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_default99) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%Le";
  long double val = 72537572375.1431341;
  s21_sprintf(str1, format, val);
  sprintf(str2, format, val);

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_default100) {
  char str1[BUFF_SIZE] = {'\0'};
  char str2[BUFF_SIZE] = {'\0'};
  char *format = "%015E";
  float val = 0;
  s21_sprintf(str1, format, val);
  sprintf(str2, format, val);

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_default101) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%15e";
  float val = 0;
  s21_sprintf(str1, format, val);
  sprintf(str2, format, val);

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_default102) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "% .0e %.le %Le %e %le %Le";
  float val = 0;
  double val1 = 0;
  long double val2 = 3515315.153151;
  float val3 = 5.5;
  double val4 = 0.094913941;
  long double val5 = 95919539159.53151351131;
  s21_sprintf(str1, format, val, val1, val2, val3, val4, val5);
  sprintf(str2, format, val, val1, val2, val3, val4, val5);

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_default103) {
  char str1[BUFF_SIZE] = {'\0'};
  char str2[BUFF_SIZE] = {'\0'};
  char *format = "%.17LE";
  long double val = 4134121;
  s21_sprintf(str1, format, val);
  sprintf(str2, format, val);

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_default104) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  ck_assert_int_eq(s21_sprintf(str1, "abc"), sprintf(str2, "abc"));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_default105) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "abc"), sprintf(str2, "abc"));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_default106) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%15o";
  int val = 14140;
  s21_sprintf(str1, format, val);
  sprintf(str2, format, val);

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_default107) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%-16o";
  int val = 14140;
  s21_sprintf(str1, format, val);
  sprintf(str2, format, val);

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_default108) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%.51o";
  int val = 14140;
  s21_sprintf(str1, format, val);
  sprintf(str2, format, val);

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_default109) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%-5.51o";
  int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_default110) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%o";
  ck_assert_int_eq(s21_sprintf(str1, format, 0), sprintf(str2, format, 0));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_default111) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%#o";
  int val = 57175;
  s21_sprintf(str1, format, val);
  sprintf(str2, format, val);

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_default112) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%hd";
  short int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_default113) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%lo";
  long int val = 949149114140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

// START_TEST(test_default114) {
//   char str1[BUFF_SIZE];
//   char str2[BUFF_SIZE];

//   char *format = "%lo, %o, %ho, %.5o, %5.o";
//   long int val = 949149114140;
//   ck_assert_int_eq(
//       s21_sprintf(str1, format, val, 14, 1441, 14414, 9681),
//       sprintf(str2, format, val, (unsigned)14, (unsigned short)1441,
//               (unsigned)14414, (unsigned)9681));

//   ck_assert_str_eq(str1, str2);
// }
// END_TEST

START_TEST(test_default115) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%lo";
  long int val = 84518;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_default116) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%#o";
  int val = -57175;
  s21_sprintf(str1, format, val);
  sprintf(str2, format, val);

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_default117) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%#- 10o";
  int val = -573375;
  s21_sprintf(str1, format, val);
  sprintf(str2, format, val);

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_default118) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%5x";
  unsigned val = 858158158;
  s21_sprintf(str1, format, val);
  sprintf(str2, format, val);

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_default119) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%#-10x";
  unsigned val = 858158158;
  s21_sprintf(str1, format, val);
  sprintf(str2, format, val);

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_default120) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%.15x";
  unsigned val = 858158158;
  s21_sprintf(str1, format, val);
  sprintf(str2, format, val);

  ck_assert_str_eq(str1, str2);
}
END_TEST
// START_TEST(test_default121) {
//   char str1[BUFF_SIZE];
//   char str2[BUFF_SIZE];

//   char *format = "%#-10x %x %X %#x %#X %5.5x";
//   unsigned val = 858158158;
//   s21_sprintf(str1, format, val, val, val, val, val, val);
//   sprintf(str2, format, val, val, val, val, val, val);

//   ck_assert_str_eq(str1, str2);
// }
// END_TEST
START_TEST(test_default122) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%#-5.10x";
  unsigned val = 858158158;
  s21_sprintf(str1, format, val);
  sprintf(str2, format, val);

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_default123) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%#x";
  unsigned val = 0;
  s21_sprintf(str1, format, val);
  sprintf(str2, format, val);

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_default124) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%#x";
  unsigned val = 18571;
  s21_sprintf(str1, format, val);
  sprintf(str2, format, val);

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_default125) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%#hx";
  unsigned short val = 12352;
  s21_sprintf(str1, format, val);
  sprintf(str2, format, val);

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_default126) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%#lx";
  unsigned long val = 18571757371571;
  s21_sprintf(str1, format, val);
  sprintf(str2, format, val);

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_default127) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%#2x";
  unsigned val = 1;
  s21_sprintf(str1, format, val);
  sprintf(str2, format, val);

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_default128) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%#30x";
  unsigned val = 1;
  s21_sprintf(str1, format, val);
  sprintf(str2, format, val);

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_default129) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%p";
  s21_sprintf(str1, format, format);
  sprintf(str2, format, format);

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_default130) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%15p";
  s21_sprintf(str1, format, format);
  sprintf(str2, format, format);

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_default131) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%.5p";
  s21_sprintf(str1, format, format);
  sprintf(str2, format, format);

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_default132) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%p";
  char *ptr = "(nil)";
  s21_sprintf(str1, format, ptr);
  sprintf(str2, format, ptr);

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_default133) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  int ret = 0;
  char *format = "How many chars written before n %n";
  s21_sprintf(str1, format, &ret);
  sprintf(str2, format, &ret);

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_default134) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  int n1;
  int n2;
  s21_sprintf(str1, "%d%n", 123, &n1);
  sprintf(str2, "%d%n", 123, &n2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_default135) {
  char result[512];
  char assert[512];
  char *d = "2147";
  s21_sprintf(result, "%101s", d);
  sprintf(assert, "%101s", d);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default136) {
  char result[512];
  char assert[512];
  char c = 'z';
  s21_sprintf(result, "Count: %12lc", c);
  sprintf(assert, "Count: %12lc", c);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default137) {
  char result[20] = {'\0'};
  char assert[20] = {'\0'};
  char c = 'z';
  s21_sprintf(result, "Count: %-12lc", c);
  sprintf(assert, "Count: %-12lc", c);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default138) {
  char str1[BUFF_SIZE] = {'\0'};
  char str2[BUFF_SIZE] = {'\0'};

  char *format = "wchar: %lc";
  wchar_t w = L'A';
  int a = s21_sprintf(str1, format, w);
  int b = sprintf(str2, format, w);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(a, b);
}
END_TEST

//
//
//
//

START_TEST(memchr_test) {
  char *s1 = "This is a s21_memchr test";

  ck_assert_ptr_eq(s21_memchr(s1, 's', 0), memchr(s1, 's', 0));
  ck_assert_ptr_eq(s21_memchr(s1, 's', 2), memchr(s1, 's', 2));
  ck_assert_ptr_eq(s21_memchr(s1, 's', 50), memchr(s1, 's', 50));
  ck_assert_ptr_eq(s21_memchr(s1, 'u', 50), memchr(s1, 'u', 50));
  ck_assert_ptr_eq(s21_memchr(s1, 'u', 32), memchr(s1, 'u', 32));
}
END_TEST

START_TEST(memcmp_test) {
  char *s1 = "This is a 1st string s21_memcmp test";
  char *s2 = "This is a 2nd string s21_memcmp test";

  ck_assert_msg(s21_memcmp(s1, s2, 256) == memcmp(s1, s2, 256),
                "1st memcmp test failed.");
  ck_assert_msg(s21_memcmp(s1, s2, 2) == memcmp(s1, s2, 2),
                "2nd memcmp test failed.");
  ck_assert_msg(s21_memcmp(s1, s2, 123) == memcmp(s1, s2, 123),
                "3rd memcmp test failed.");
  ck_assert_msg(s21_memcmp(s1, s2, 36) == memcmp(s1, s2, 36),
                "4rth memcmp test failed.");
}
END_TEST

START_TEST(memcpy_test) {
  char *src1 = "schesrdsfdsfdsfesr";
  int len = s21_strlen(src1);
  char dest1[100] = {0};
  char dest2[100] = {0};
  char dest3[100] = {0};
  char dest4[100] = {0};
  char dest5[100] = {0};
  char dest6[100] = {0};
  char dest7[100] = {0};
  char dest8[100] = {0};
  char dest9[100] = {0};
  char dest10[100] = {0};

  s21_memcpy(dest1, src1, len + 1);
  memcpy(dest2, src1, len + 1);

  s21_memcpy(dest3, src1, 5);
  memcpy(dest4, src1, 5);

  s21_memcpy(dest5, src1, 0);
  memcpy(dest6, src1, 0);

  s21_memcpy(dest7, src1, 18);
  memcpy(dest8, src1, 18);

  s21_memcpy(dest9, src1, 1);
  memcpy(dest10, src1, 1);

  ck_assert_str_eq(dest1, dest2);
  ck_assert_str_eq(dest3, dest4);
  ck_assert_str_eq(dest5, dest6);
  ck_assert_str_eq(dest7, dest8);
  ck_assert_str_eq(dest9, dest10);
}
END_TEST

START_TEST(memmove_test) {
  char *src1 = "schesrdsfdsfdsfesr";
  int len = s21_strlen(src1);
  char dest1[100] = {0};
  char dest2[100] = {0};
  char dest3[100] = {0};
  char dest4[100] = {0};
  char dest5[100] = {0};
  char dest6[100] = {0};
  char dest7[100] = {0};
  char dest8[100] = {0};
  char dest9[100] = {0};
  char dest10[100] = {0};

  s21_memmove(dest1, src1, len + 1);
  memmove(dest2, src1, len + 1);

  s21_memmove(dest3, src1, 5);
  memmove(dest4, src1, 5);

  s21_memmove(dest5, src1, 0);
  memmove(dest6, src1, 0);

  s21_memmove(dest7, src1, 18);
  memmove(dest8, src1, 18);

  s21_memmove(dest9, src1, 1);
  memmove(dest10, src1, 1);

  ck_assert_msg(memcmp(dest1, dest2, len) == 0, "1st memmove test failed.");
  ck_assert_msg(memcmp(dest3, dest4, 5) == 0, "2nd memmove test failed.");
  ck_assert_msg(memcmp(dest5, dest6, 0) == 0, "3rd memmove test failed.");
  ck_assert_msg(memcmp(dest7, dest8, 18) == 0, "4rth memmove test failed.");
  ck_assert_msg(memcmp(dest9, dest10, 1) == 0, "5rth memmove test failed.");
}
END_TEST

START_TEST(memset_test) {
  char str1[] = "School is cool";
  char str2[] = "School-21";
  char str3[] = "amogus";
  char str4[] = "This is a string!";
  char str5[] = "Shrek";
  char res1[] = "School is cool";
  char res2[] = "School-21";
  char res3[] = "amogus";
  char res4[] = "This is a string!";
  char res5[] = "Shrek";

  s21_memset(str1, '_', 5);
  s21_memset(str2, '_', 4);
  s21_memset(str3, 'M', 2);
  s21_memset(str4, '-', 1);
  s21_memset(str5, 'S', 1);

  memset(res1, '_', 5);
  memset(res2, '_', 4);
  memset(res3, 'M', 2);
  memset(res4, '-', 1);
  memset(res5, 'S', 1);

  ck_assert_msg(memcmp(str1, res1, sizeof(str1)) == 0,
                "1st memset test failed");
  ck_assert_msg(memcmp(str2, res2, sizeof(str2)) == 0,
                "2nd memset test failed");
  ck_assert_msg(memcmp(str3, res3, sizeof(str3)) == 0,
                "3rd memset test failed");
  ck_assert_msg(memcmp(str4, res4, sizeof(str4)) == 0,
                "4rth memset test failed");
  ck_assert_msg(memcmp(str5, res5, sizeof(str5)) == 0,
                "5rth memset test failed");
}
END_TEST

START_TEST(strcat_test) {
  char str1[21] = "TEST";
  char str2[8] = "strcat";
  char str3[9] = "function";
  char str4[1] = "";
  char str5[2] = " ";

  s21_strcat(str1, str5);
  ck_assert_msg(!memcmp(str1, "TEST ", 6), "1st strcat test failed");

  s21_strcat(str1, str2);
  ck_assert_msg(!memcmp(str1, "TEST strcat", 12), "2nd strcat test failed");

  s21_strcat(str1, str5);
  ck_assert_msg(!memcmp(str1, "TEST strcat ", 13), "3rd strcat test failed");

  s21_strcat(str1, str3);
  ck_assert_msg(!memcmp(str1, "TEST strcat function", 21),
                "4rth strcat test failed");

  s21_strcat(str1, str4);
  ck_assert_msg(!memcmp(str1, "TEST strcat function", 21),
                "5th strcat test failed");
}
END_TEST

START_TEST(strncat_test) {
  char str1[25] = "TEST";
  char str2[8] = "strncat";
  char str3[35] = "function";
  char str4[1] = "";
  char str5[30] = "amogus";

  s21_strncat(str1, str2, 3);
  ck_assert_msg(!memcmp(str1, "TESTstr", 8), "1st strncat test failed");

  s21_strncat(str1, str4, 3);
  ck_assert_msg(!memcmp(str1, "TESTstr", 8), "2nd strncat test failed");

  s21_strncat(str2, str4, 1);
  ck_assert_msg(!memcmp(str2, "strncat", 8), "3rd strncat test failed");

  s21_strncat(str5, str3, 3);
  ck_assert_msg(!memcmp(str5, "amogusfun", 10), "4rth strncat test failed");
}
END_TEST

START_TEST(strchr_test) {
  char *str1 = "TEST";
  char *str2 = "strchr";
  char *str3 = "function";
  char *str4 = "";
  char *str5 = "amogus";
  ck_assert_str_eq(s21_strchr(str1, 'E'), strchr(str1, 'E'));
  ck_assert_str_eq(s21_strchr(str3, 'i'), strchr(str3, 'i'));
  ck_assert_str_eq(s21_strchr(str5, 'a'), strchr(str5, 'a'));
  ck_assert_str_eq(s21_strchr(str1, 'E'), strchr(str1, 'E'));
  ck_assert_ptr_eq(s21_strchr(str2, 'E'), strchr(str2, 'E'));
  ck_assert_str_eq(s21_strchr(str3, 'i'), strchr(str3, 'i'));
  ck_assert_ptr_eq(s21_strchr(str4, ' '), strchr(str4, ' '));
  ck_assert_str_eq(s21_strchr(str5, 'a'), strchr(str5, 'a'));
}
END_TEST

START_TEST(strcmp_test) {
  char t1[] = "Sample Text";
  char t2[] = "Sample Text Plus Some Text";
  ck_assert_msg(s21_strcmp(t1, t2) == -32, "1st strcmp test failed");

  char t3[] = "AAA";
  char t4[] = "B";
  ck_assert_msg(s21_strcmp(t3, t4) == -1, "2nd strcmp test failed");

  char t5[] = "A\0BCD";
  char t6[] = "A";
  ck_assert_msg(s21_strcmp(t5, t6) == 0, "3rd strcmp test failed");

  char t7[] = "amogus";
  char t8[] = "m";
  ck_assert_msg(s21_strcmp(t7, t8) == -12, "4rth strcmp test failed");

  char t9[] = "shrek";
  char t10[] = "as";
  ck_assert_msg(s21_strcmp(t9, t10) == 18, "5th strcmp test failed");

  char t11[] = "бг";
  char t12[] = "бг";
  ck_assert_msg(s21_strcmp(t11, t12) == 0, "5th strcmp test failed");
}
END_TEST

START_TEST(strncmp_test) {
  char *t1 = "Sample Text";
  char *t2 = "Sample Text Plus Some Text";
  ck_assert_msg(!s21_strncmp(t1, t2, 10) && !strncmp(t1, t2, 10),
                "1st strncmp test failed");

  ck_assert_msg(s21_strncmp(t1, t2, 14) < 0 && strncmp(t1, t2, 14) < 0,
                "2nd strncmp test failed");
  char *t3 = "";
  char *t4 = "A";
  ck_assert_msg(s21_strncmp(t3, t4, 0) == 0 && strncmp(t3, t4, 0) == 0,
                "3rd strncmp test failed");
  ck_assert_msg(s21_strncmp(t3, t4, 1) < 0 && strncmp(t3, t4, 1) < 0,
                "3rd strncmp test failed");
  char *t5 = "ShrekAmogus";
  char *t6 = "Shr";
  ck_assert_msg(s21_strncmp(t5, t6, 5) > 0 && strncmp(t5, t6, 5) > 0,
                "4rth strncmp test failed");
  ck_assert_msg(s21_strncmp(t5, t6, 0) == 0 && strncmp(t5, t6, 0) == 0,
                "5th strncmp test failed");
}
END_TEST

START_TEST(strcpy_test) {
  char s1[50] = "Sample Text";
  char d1[50] = "";
  s21_strcpy(d1, s1);
  ck_assert_msg(!strcmp(d1, s1), "1st  strcpy test failed");

  char s2[50] = "AAAAA";
  char d2[50] = "NO";
  s21_strcpy(d2, s2);
  ck_assert_msg(!strcmp(d2, s2), "2nd strcpy test failed");

  char s3[50] = "";
  char d3[50] = "HELLO";
  s21_strcpy(d3, s3);
  ck_assert_msg(!strcmp(d3, s3), "3rd strcpy test failed");

  char s4[50] = "amogus";
  char d4[50] = "HELLO";
  s21_strcpy(d4, s4);
  ck_assert_msg(!strcmp(d4, s4), "4rth strcpy test failed");

  char s5[50] = "Shrek";
  char d5[50] = "what";
  s21_strcpy(d5, s5);
  ck_assert_msg(!strcmp(d5, s5), "5th strcpy test failed");
}
END_TEST

START_TEST(strncpy_test) {
  char s1[50] = "Sample Text";
  char d1[50] = "";
  s21_strncpy(d1, s1, 2);
  ck_assert_msg(!strcmp(d1, "Sa"), "1st strncpy test failed");

  char s2[50] = "AAAAA";
  char d2[50] = "NO";
  s21_strncpy(d2, s2, 0);
  ck_assert_msg(!strcmp(d2, "NO"), "2nd strncpy test failed");

  char s3[50] = "H";
  char d3[50] = "fELLO";
  s21_strncpy(d3, s3, 1);
  ck_assert_msg(!strcmp(d3, "HELLO"), "3rd strncpy test failed");

  char s4[50] = "amo";
  char d4[50] = "qwegus";
  s21_strncpy(d4, s4, 3);
  ck_assert_msg(!strcmp(d4, "amogus"), "4rth strncpy test failed");

  char s5[50] = "shrek";
  char d5[50] = "s";
  s21_strncpy(d5, s5, 5);
  ck_assert_msg(!strcmp(d5, "shrek"), "5th strncpy test failed");
}
END_TEST

START_TEST(strcspn_test) {
  char *str1 = "0123456789";
  char *str2 = "9876";
  ck_assert_msg(s21_strcspn(str1, str2) == strcspn(str1, str2),
                "1st strcspn test failed");

  char *str3 = "0123456789";
  char *str4 = "";
  ck_assert_msg(s21_strcspn(str3, str4) == strcspn(str3, str4),
                "2nd strcspn test failed");

  char *str5 = "";
  char *str6 = "123";
  ck_assert_msg(s21_strcspn(str5, str6) == strcspn(str5, str6),
                "3rd strcspn test failed");

  char *str7 = "1337";
  char *str8 = "228";
  ck_assert_msg(s21_strcspn(str7, str8) == strcspn(str7, str8),
                "4rth strcspn test failed");

  char *str9 = "19642";
  char *str10 = "64";
  ck_assert_msg(s21_strcspn(str9, str10) == strcspn(str9, str10),
                "5th strcspn test failed");
}
END_TEST

START_TEST(strlen_test) {
  char *s1 = "0123456789";
  ck_assert_msg(s21_strlen(s1) == strlen(s1), "1st strlen test failed");

  char *s2 = "";
  ck_assert_msg(s21_strlen(s2) == strlen(s2), "2nd strlen test failed");

  char *s3 = "amogus";
  ck_assert_msg(s21_strlen(s3) == strlen(s3), "3rd strlen test failed");

  char *s4 = "shrek";
  ck_assert_msg(s21_strlen(s4) == strlen(s4), "4rth strlen test failed");

  char *s5 = "is love";
  ck_assert_msg(s21_strlen(s5) == strlen(s5), "5th strlen test failed");
}
END_TEST

START_TEST(strpbrk_test) {
  char *str1 = "hello";
  char *str2 = "hel";
  char *res1, *res2;
  res1 = s21_strpbrk(str1, str2);
  res2 = strpbrk(str1, str2);
  ck_assert_str_eq(res1, res2);

  char *str4 = "ab";
  res1 = s21_strpbrk(str1, str4);
  res2 = strpbrk(str1, str4);
  ck_assert_ptr_eq(res1, res2);

  char *str5 = "o";
  res1 = s21_strpbrk(str1, str5);
  res2 = strpbrk(str1, str5);
  ck_assert_str_eq(res1, res2);

  char *str6 = "abcdefghjkl";
  char *str7 = "abcd";
  res1 = s21_strpbrk(str6, str7);
  res2 = strpbrk(str6, str7);
  ck_assert_str_eq(res1, res2);

  char *str8 = "amogus is shrek?";
  char *str9 = "is";
  res1 = s21_strpbrk(str8, str9);
  res2 = s21_strpbrk(str8, str9);
  ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(strrchr_test) {
  char *s1 = "School-21";
  char *s2 = "";
  char *s3 = "amogus";

  ck_assert_msg(s21_strrchr(s1, 'm') == strrchr(s1, 'm'),
                "1st strrchr test failed");
  ck_assert_msg(s21_strrchr(s1, 'o') == strrchr(s1, 'o'),
                "2nd strrchr test failed");
  ck_assert_msg(s21_strrchr(s2, 'o') == strrchr(s2, 'o'),
                "3rd strrchr test failed");
  ck_assert_msg(s21_strrchr(s3, ' ') == strrchr(s3, ' '),
                "4rth strrchr test failed");
  ck_assert_msg(s21_strrchr(s3, 's') == strrchr(s3, 's'),
                "5th strrchr test failed");
}
END_TEST

START_TEST(strspn_test) {
  char *s1 = "School-21";
  char *s2 = "ho";
  char *s3 = "";

  ck_assert_msg(s21_strspn(s1, s2) == strspn(s1, s2), "1st strspn test failed");
  ck_assert_msg(s21_strspn(s3, s2) == strspn(s3, s2), "2nd strspn test failed");
  ck_assert_msg(s21_strspn(s2, s3) == strspn(s2, s3), "3rd strspn test failed");
  ck_assert_msg(s21_strspn(s1, s3) == strspn(s1, s3),
                "4rth strspn test failed");
  ck_assert_msg(s21_strspn(s3, s1) == strspn(s3, s1), "5th strspn test failed");
}
END_TEST

START_TEST(strstr_test) {
  char *s1 = "School-21";
  char *s2 = "ho";
  char *s3 = "";

  ck_assert_msg(s21_strstr(s1, s2) == strstr(s1, s2), "1st strstr test failed");
  ck_assert_msg(s21_strstr(s1, s3) == strstr(s1, s3), "2nd strstr test failed");
  ck_assert_msg(s21_strstr(s3, s2) == strstr(s3, s2), "3rd strstr test failed");
  ck_assert_msg(s21_strstr(s2, s3) == strstr(s2, s3),
                "4rth strstr test failed");
  ck_assert_msg(s21_strstr(s3, s1) == strstr(s3, s1), "5th strstr test failed");
}
END_TEST

START_TEST(to_upper_test) {
  char destination[] = "Here w0 are123\0";
  char *test01 = s21_to_upper(destination);
  ck_assert_str_eq(test01, "HERE W0 ARE123");
  free(test01);

  char destination2[] = "Here w0 are\n\0";
  char *test02 = s21_to_upper(destination2);
  ck_assert_str_eq(test02, "HERE W0 ARE\n");
  free(test02);

  char destination3[] = "a\n\0";
  char *test03 = s21_to_upper(destination3);
  ck_assert_str_eq(test03, "A\n");
  free(test03);

  char destination4[] = " \n\0";
  char *test04 = s21_to_upper(destination4);
  ck_assert_str_eq(test04, " \n");
  free(test04);

  char destination5[] = " \0";
  char *test05 = s21_to_upper(destination5);
  ck_assert_str_eq(test05, " ");
  free(test05);

  char destination6[] = "\n\0";
  char *test06 = s21_to_upper(destination6);
  ck_assert_str_eq(test06, "\n");
  free(test06);

  char destination7[] = "\0";
  char *test07 = s21_to_upper(destination7);
  ck_assert_str_eq(test07, "");
  free(test07);
}
END_TEST

START_TEST(to_lower_test) {
  char destination[] = "HERE W0 ARE123\0";
  char *test01 = s21_to_lower(destination);
  ck_assert_str_eq(test01, "here w0 are123");
  free(test01);

  char destination2[] = "HERE W0 ARE\n\0";
  char *test02 = s21_to_lower(destination2);
  ck_assert_str_eq(test02, "here w0 are\n");
  free(test02);

  char destination3[] = "A\n\0";
  char *test03 = s21_to_lower(destination3);
  ck_assert_str_eq(test03, "a\n");
  free(test03);

  char destination4[] = " \n\0";
  char *test04 = s21_to_lower(destination4);
  ck_assert_str_eq(test04, " \n");
  free(test04);

  char destination5[] = " \0";
  char *test05 = s21_to_lower(destination5);
  ck_assert_str_eq(test05, " ");
  free(test05);

  char destination6[] = "\n\0";
  char *test06 = s21_to_lower(destination6);
  ck_assert_str_eq(test06, "\n");
  free(test06);

  char destination7[] = "\0";
  char *test07 = s21_to_lower(destination7);
  ck_assert_str_eq(test07, "");
  free(test07);
}
END_TEST

START_TEST(insert_test) {
  char *s1 = "School-21 test";
  char *s2 = "insert ";
  char *s3 = "amogus";
  char *s4 = "is";
  char *s5 = "shrek";
  char *res1 = s21_insert(s1, " ", 3);
  char *res2 = s21_insert(s5, s3, 5);
  char *res3 = s21_insert(s3, s5, 0);
  char *res4 = s21_insert(s5, s4, 5);
  char *res5 = s21_insert(s2, s1, 4);

  ck_assert_str_eq(res1, "Sch ool-21 test");
  ck_assert_str_eq(res2, "shrekamogus");
  ck_assert_str_eq(res3, "shrekamogus");
  ck_assert_str_eq(res4, "shrekis");
  ck_assert_str_eq(res5, "inseSchool-21 testrt ");

  free(res1);
  free(res2);
  free(res3);
  free(res4);
  free(res5);
}
END_TEST

START_TEST(test_trim_1) {
  char s1[30] = "-?hello, world!";
  char s3[] = "!?-";
  char s4[] = "hello, world";
  char *s2 = s21_trim(s1, s3);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_trim_2) {
  char s1[30] = "";
  char s3[] = "";
  char *s4 = "";
  char *s2 = s21_trim(s1, s3);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_trim_3) {
  char *s1 = NULL;
  char s3[] = "";
  char *s4 = NULL;
  char *s2 = s21_trim(s1, s3);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_trim_4) {
  char s1[30] = "!!!abcdefghij!?!";
  char s3[] = "!?";
  char s4[] = "abcdefghij";
  char *s2 = s21_trim(s1, s3);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_trim_5) {
  char s1[30] = "abc";
  char s3[] = "333";
  char *s4 = "abc";
  char *s2 = s21_trim(s1, s3);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_trim_6) {
  char s1[30] = "hello, world!";
  char s3[] = "?!";
  char *s4 = "hello, world";
  char *s2 = s21_trim(s1, s3);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_trim_7) {
  char *s1 = NULL;
  char *s3 = NULL;
  char *s4 = NULL;
  char *s2 = s21_trim(s1, s3);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_trim_8) {
  char s1[30] = "";
  char s3[] = "";
  char s4[] = "";
  char *s2 = s21_trim(s1, s3);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_trim_9) {
  char s1[] = " wtf ";
  char *s3 = NULL;
  char *s4 = " wtf ";
  char *s2 = s21_trim(s1, s3);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_trim_10) {
  char s1[] = " wtf ";
  char *s3 = "";
  char *s4 = " wtf ";
  char *s2 = s21_trim(s1, s3);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(strerror_test) {
  char *str1 = s21_strerror(20);
  char *str2 = strerror(20);
  ck_assert_str_eq(str1, str2);

  char *str3 = s21_strerror(12);
  char *str4 = strerror(12);
  ck_assert_str_eq(str3, str4);

  char *str5 = s21_strerror(1337);
  char *str6 = strerror(1337);
  ck_assert_str_eq(str5, str6);

  char *str7 = s21_strerror(1);
  char *str8 = strerror(1);
  ck_assert_str_eq(str7, str8);

  char *str9 = s21_strerror(25);
  char *str10 = strerror(25);
  ck_assert_str_eq(str9, str10);
}
END_TEST

START_TEST(strtok_test) {
  char test1[50] = "aboba,hello,world,trim";
  char test2[50] = "aboba,hello,world,trim";
  char delim1[10] = "123,";
  char *orig1 = {0}, *copy1 = {0};
  orig1 = strtok(test1, delim1);
  copy1 = s21_strtok(test2, delim1);
  char orig_res1[1000] = {0};
  char copy_res1[1000] = {0};
  while (orig1 != NULL) {
    strcat(orig_res1, orig1);
    orig1 = strtok(NULL, delim1);
  }
  while (copy1 != NULL) {
    strcat(copy_res1, copy1);
    copy1 = s21_strtok(NULL, delim1);
  }
  ck_assert_str_eq(orig_res1, copy_res1);

  char str[] = "School-21";
  char *tok1 = s21_strtok(str, "-");
  char *tok2 = strtok(str, "-");
  char *tok3 = s21_strtok(str, "");
  char *tok4 = strtok(str, "");
  char *tok5 = s21_strtok(str, "oo");
  char *tok6 = strtok(str, "oo");
  char *tok7 = s21_strtok(str, "Sc");
  char *tok8 = strtok(str, "Sc");
  char *tok9 = s21_strtok(str, "21");
  char *tok10 = strtok(str, "21");

  ck_assert_msg(!strcmp(tok1, tok2), "1st strtok test failed");
  ck_assert_msg(!strcmp(tok3, tok4), "2nd strtok test failed");
  ck_assert_msg(!strcmp(tok5, tok6), "3rd strtok test failed");
  ck_assert_msg(!strcmp(tok7, tok8), "4rth strtok test failed");
  ck_assert_msg(!strcmp(tok9, tok10), "5th strtok test failed");
}
END_TEST

char c[255] = {}, d[255] = {}, x1 = 't';
int n = 2100, n1 = 0, n2 = -21;
short sh = 123, sh1 = -123;
float f = 21.21, f1 = -21.21;
long int lg = 12345678912345, lg1 = -12345678912345;

START_TEST(sprintf_percent) {
  s21_sprintf(c, "%% %d", n);
  sprintf(d, "%% %d", n);
  ck_assert_str_eq(c, d);
}
END_TEST

START_TEST(sprintf_d) {
  s21_sprintf(c, "%d %d %d %hd %hd %ld %ld %10ld", n, n1, n2, sh, sh1, lg, lg1,
              lg1);
  sprintf(d, "%d %d %d %hd %hd %ld %ld %10ld", n, n1, n2, sh, sh1, lg, lg1,
          lg1);
  ck_assert_str_eq(c, d);

  s21_sprintf(c, "%-10d %10d %10d %*d %2d", 21, n2, n, 10, n, n2);
  sprintf(d, "%-10d %10d %10d %*d %2d", 21, n2, n, 10, n, n2);
  ck_assert_str_eq(c, d);

  s21_sprintf(c,
              "%.*d %3.10d %.d %-+.5d %-+10.5d %.10d %.10d %2.2d %.d % d %.0d",
              10, n, n2, 42, 21, 10, n, n2, -21, x1, 21, -42);
  sprintf(d, "%.*d %3.10d %.d %-+.5d %-+10.5d %.10d %.10d %2.2d %.d % d %.0d",
          10, n, n2, 42, 21, 10, n, n2, -21, x1, 21, -42);
  ck_assert_str_eq(c, d);
}
END_TEST

START_TEST(sprintf_c) {
  s21_sprintf(c, "%c %10c %-10c", '!', 'a', 'b');
  sprintf(d, "%c %10c %-10c", '!', 'a', 'b');
  ck_assert_str_eq(c, d);

  s21_sprintf(c, "%c %c %c", CHAR_MAX, CHAR_MIN, UCHAR_MAX);
  sprintf(d, "%c %c %c", CHAR_MAX, CHAR_MIN, UCHAR_MAX);
  ck_assert_str_eq(c, d);
}
END_TEST

START_TEST(sprintf_s) {
  s21_sprintf(c, "%s %10s %-10s %-3s %.s %.3s %.10s", "hello", "hello", "hello",
              "hello", "hello", "hello", "hello");
  sprintf(d, "%s %10s %-10s %-3s %.s %.3s %.10s", "hello", "hello", "hello",
          "hello", "hello", "hello", "hello");
  ck_assert_str_eq(c, d);

  s21_sprintf(c, "%ls %10ls %-10ls %-3ls %.ls %.3ls %.10ls", L"hello", L"hello",
              L"hello", L"hello", L"hello", L"hello", L"hello");
  sprintf(d, "%ls %10ls %-10ls %-3ls %.ls %.3ls %.10ls", L"hello", L"hello",
          L"hello", L"hello", L"hello", L"hello", L"hello");
  ck_assert_str_eq(c, d);
}
END_TEST

char *get_random_str() {
  srand(time(NULL));
  int len = rand() % (NMAX - 1) + 1;
  char *str = (char *)malloc(len + 1);
  for (int i = 0; i < len; i++) {
    str[i] = (char)(rand() % ('z' - 'a' + 1) + 'a');
  }
  str[len] = '\0';
  return str;
}

START_TEST(test_memchr) {
  char *str = get_random_str();
  int len = strlen(str);
  char target = (char)(rand() % ('z' - 'a' + 1) + 'a');
  ck_assert_ptr_eq(memchr(str, target, len), s21_memchr(str, target, len));
  free(str);
}
END_TEST

START_TEST(test_memcpy) {
  char *src = get_random_str();
  int len = strlen(src);
  char *dst = (char *)malloc(len + 1);
  char *expected_dst = (char *)malloc(len + 1);
  memcpy(expected_dst, src, len);
  s21_memcpy(dst, src, len);
  ck_assert_str_eq(dst, expected_dst);
  free(src);
  free(dst);
  free(expected_dst);
}
END_TEST

START_TEST(test_memcmp) {
  char *s1 = get_random_str();
  char *s2 = get_random_str();
  int len = rand() % (NMAX - 1) + 1;
  ck_assert_int_eq(memcmp(s1, s2, len), s21_memcmp(s1, s2, len));
  free(s1);
  free(s2);
}
END_TEST

START_TEST(test_strtok) {
  char input[] = "This is a test string";
  char *result;
  char *delimiter = " ";
  result = strtok(input, delimiter);
  ck_assert_str_eq(result, "This");
  result = strtok(NULL, delimiter);
  ck_assert_str_eq(result, "is");
  result = strtok(NULL, delimiter);
  ck_assert_str_eq(result, "a");
  result = strtok(NULL, delimiter);
  ck_assert_str_eq(result, "test");
  result = strtok(NULL, delimiter);
  ck_assert_str_eq(result, "string");
  result = strtok(NULL, delimiter);
  ck_assert_ptr_eq(result, NULL);
}
END_TEST

START_TEST(test_strstr) {
  char *haystack = get_random_str();
  char *needle = get_random_str();
  ck_assert_ptr_eq(strstr(haystack, needle), s21_strstr(haystack, needle));
  free(haystack);
  free(needle);
}
END_TEST

START_TEST(test_strcpy) {
  char *src = get_random_str();
  char *dst = (char *)malloc(strlen(src) + 1);
  strcpy(dst, src);
  s21_strcpy(dst, src);
  ck_assert_str_eq(dst, src);
  free(src);
  free(dst);
}
END_TEST

START_TEST(test_strcmp) {
  char *s1 = get_random_str();
  char *s2 = get_random_str();
  ck_assert_int_eq(strcmp(s1, s2), s21_strcmp(s1, s2));
  free(s1);
  free(s2);
}
END_TEST

START_TEST(test_strlen) {
  char *str = get_random_str();
  ck_assert_int_eq(strlen(str), s21_strlen(str));
  free(str);
}
END_TEST

START_TEST(test_strchr) {
  char *str = get_random_str();
  char *target = str + (rand() % strlen(str));
  ck_assert_ptr_eq(strchr(str, *target), s21_strchr(str, *target));
  free(str);
}
END_TEST

START_TEST(test_strcat) {
  char *s1 = get_random_str();
  char *s2 = get_random_str();
  char *expected_str = (char *)malloc(strlen(s1) + strlen(s2) + 1);
  strcpy(expected_str, s1);
  strcat(expected_str, s2);
  char *my_str = (char *)malloc(strlen(s1) + strlen(s2) + 1);
  strcpy(my_str, s1);
  s21_strcat(my_str, s2);
  ck_assert_str_eq(my_str, expected_str);
  free(s1);
  free(s2);
  free(expected_str);
  free(my_str);
}
END_TEST

START_TEST(test_memmove) {
  char *s1 = get_random_str();
  int len = strlen(s1);
  int offset = rand() % len;
  char *expected_s1 = (char *)malloc(len + 1);
  memcpy(expected_s1, s1, len);
  s21_memmove(s1 + offset, s1, len - offset);
  memmove(expected_s1 + offset, expected_s1, len - offset);
  ck_assert_str_eq(s1, expected_s1);
  free(s1);
  free(expected_s1);
}
END_TEST

START_TEST(test_memset) {
  char *s1 = get_random_str();
  int len = strlen(s1);
  char target = (char)(rand() % ('z' - 'a' + 1) + 'a');
  char *s2 = (char *)malloc(len + 1);
  memcpy(s2, s1, len);
  s21_memset(s1, target, len);
  memset(s2, target, len);
  ck_assert_str_eq(s1, s2);
  free(s1);
  free(s2);
}
END_TEST

START_TEST(test_default139) {
  char result[40];
  char assert[40];
  char *s = NULL;
  s21_sprintf(result, "Count: %s abc", s);
  sprintf(assert, "Count: %s abc", s);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default140) {
  char result[40];
  char assert[40];
  wchar_t *s = NULL;
  s21_sprintf(result, "Count: %ls abc", s);
  sprintf(assert, "Count: %ls abc", s);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_sscanf_int)
{
    int x, y;
    int result = s21_sscanf("123 456", "%d %d", &x, &y);
    ck_assert_int_eq(result, 2);
    ck_assert_int_eq(x, 123);
    ck_assert_int_eq(y, 456);
}
END_TEST

START_TEST(test_sscanf_float)
{
    float x, y;
    int result = s21_sscanf("3.14 -1.23", "%f %f", &x, &y);
    ck_assert_int_eq(result, 2);
    ck_assert_float_eq_tol(x, 3.14, 0.01);
    ck_assert_float_eq_tol(y, -1.23, 0.01);
}
END_TEST

START_TEST(test_sscanf_string)
{
    char x[20], y[20];
    int result = s21_sscanf("hello world", "%s %s", x, y);
    ck_assert_int_eq(result, 2);
    ck_assert_str_eq(x, "hello");
    ck_assert_str_eq(y, "world");
}
END_TEST

START_TEST(test_sscanf_skip_whitespaces)
{
  char x[20];
  int result = s21_sscanf(" abc ", "%s", x);
  ck_assert_int_eq(result, 1);
  ck_assert_str_eq(x, "abc");
}
END_TEST

START_TEST(test_sscanf_mixed_type)
{
  int x;
  float y;
  char z[20];
  int result = s21_sscanf("123 4.56 hello", "%d %f %s", &x, &y, z);
  ck_assert_int_eq(result, 3);
  ck_assert_int_eq(x, 123);
  ck_assert_float_eq_tol(y, 4.56, 0.01);
  ck_assert_str_eq(z, "hello");
}
END_TEST

START_TEST(test_sscanf_width_specifier)
{
  char x[20], y[20];
  int result = s21_sscanf("hello world", "%5s %5s", x, y);
  ck_assert_int_eq(result, 2);
  ck_assert_str_eq(x, "hello");
  ck_assert_str_eq(y, "world");
}
END_TEST

START_TEST(test_sscanf_n_assignment)
{
  int x, y;
  int result = s21_sscanf("123 456", "%d%n %d", &x, &y, &y);
  ck_assert_int_eq(result, 2);
  ck_assert_int_eq(x, 123);
  ck_assert_int_eq(y, 456);
}
END_TEST

START_TEST(s21_sscanf_test_17_o_option) {
  uint32_t a1, a2;
  const char str[] = "          \n             \n     5";
  const char fstr[] = "%o";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}

END_TEST

START_TEST(s21_sscanf_test_18_o_option) {
  uint16_t a1, a2;
  const char str[] = "12";
  const char fstr[] = "%ho";
  uint16_t res1 = s21_sscanf(str, fstr, &a1);
  uint16_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(s21_sscanf_test_19_u_option) {
  unsigned short a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  const char str[] = "-1337 +21 --5008 3000";
  const char fstr[] = "%hu %hu %hu %hu";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(test_sscanf_spec_i_int1) {
    long long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
    const char str[] = "100 500 -600 +700";
    const char fstr[] = "%lli %lli %lli %lli";

    int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
    int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(a1, a2);
    ck_assert_int_eq(b1, b2);
    ck_assert_int_eq(c1, c2);
    ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(test_sscanf_spec_i_int2) {
    long long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
    const char str[] = "100500-600+700 123";
    const char fstr[] = "%lli %lld %lld %lli";

    int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
    int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(a1, a2);
    ck_assert_int_eq(b1, b2);
    ck_assert_int_eq(c1, c2);
    ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(test_sscanf_spec_i_int3) {
    long long a1 = 0, a2 = 0, c1 = 0, c2 = 0;
    char b1 = 0, b2 = 0, d1 = 0, d2 = 0;
    const char str[] = "100500-600+700+400";
    const char fstr[] = "%lli%c%lli%c";

    int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
    int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(a1, a2);
    ck_assert_int_eq(b1, b2);
    ck_assert_int_eq(c1, c2);
    ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(test_sscanf_oct) {
        long long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
        const char str[] = "  055555 0f 0f 0f5555555 0ddd   4    3    1 ";
        const char fstr[] = "%llo %lld %lld %lli";

        int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
        int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

        ck_assert_int_eq(res1, res2);
        ck_assert_int_eq(a1, a2);
        ck_assert_int_eq(b1, b2);
        ck_assert_int_eq(c1, c2);
        ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(test_sscanf_hex) {
    long long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
    const char str[] = " 63DD 0xf 0xf 0xf5555555 ddd   4    3    1 ";
    const char fstr[] = "%lli %lld %lld %lli";

    int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
    int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(a1, a2);
    ck_assert_int_eq(b1, b2);
    ck_assert_int_eq(c1, c2);
    ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(test_strtold_exp)
{
  char *string;
  char *stopstring;
  long double z;
  string = "eee3.14159This stopped it";
  z = s21_strtold(string, &stopstring);
  //ck_assert_ldouble_eq(z, 3.14159);
}
END_TEST

START_TEST(test_s21_isdigit_valid)
{
    ck_assert_int_eq(s21_isdigit('5'), 1);
    ck_assert_int_eq(s21_isdigit('9'), 1);
    ck_assert_int_eq(s21_isdigit('0'), 1);
}
END_TEST

START_TEST(test_s21_isdigit_invalid)
{
    ck_assert_int_eq(s21_isdigit('a'), 0);
    ck_assert_int_eq(s21_isdigit('Z'), 0);
    ck_assert_int_eq(s21_isdigit(' '), 0);
    ck_assert_int_eq(s21_isdigit('.'), 0);
}
END_TEST

START_TEST(test_s21_strntollu_valid)
{
    char *endptr;
    ck_assert_uint_eq(s21_strntollu("0x1a", &endptr, 16, 2), 26);
    ck_assert_uint_eq(s21_strntollu("0x1f", &endptr, 16, 2), 31);
    ck_assert_uint_eq(s21_strntollu("0x10", &endptr, 16, 3), 16);
}
END_TEST

Suite *s21_sprintf_suite(void) {
  Suite *s;
  TCase *tc_a;

  // Создаём сьют
  s = suite_create("[s21_string] suite");

  // Создаём кейс
  tc_a = tcase_create("[s21_sprintf] case");

  // Добавялем тесты в кейс
  tcase_add_test(tc_a, test_default);
  tcase_add_test(tc_a, test_default2);
  tcase_add_test(tc_a, test_default3);
  tcase_add_test(tc_a, test_default4);
  tcase_add_test(tc_a, test_default5);
  tcase_add_test(tc_a, test_default6);
  tcase_add_test(tc_a, test_default7);
  tcase_add_test(tc_a, test_default8);
  tcase_add_test(tc_a, test_default9);
  tcase_add_test(tc_a, test_default10);
  tcase_add_test(tc_a, test_default11);
  tcase_add_test(tc_a, test_default12);
  tcase_add_test(tc_a, test_default13);
  tcase_add_test(tc_a, test_default14);
  tcase_add_test(tc_a, test_default15);
  tcase_add_test(tc_a, test_default16);
  tcase_add_test(tc_a, test_default17);
  tcase_add_test(tc_a, test_default18);
  tcase_add_test(tc_a, test_default19);
  tcase_add_test(tc_a, test_default20);
  tcase_add_test(tc_a, test_default21);
  tcase_add_test(tc_a, test_default22);
  tcase_add_test(tc_a, test_default23);
  tcase_add_test(tc_a, test_default24);
  tcase_add_test(tc_a, test_default25);
  tcase_add_test(tc_a, test_default26);
  tcase_add_test(tc_a, test_default27);
  tcase_add_test(tc_a, test_default28);
  tcase_add_test(tc_a, test_default29);
  tcase_add_test(tc_a, test_default30);
  tcase_add_test(tc_a, test_default31);
  tcase_add_test(tc_a, test_default32);
  tcase_add_test(tc_a, test_default33);
  tcase_add_test(tc_a, test_default34);
  tcase_add_test(tc_a, test_default35);
  tcase_add_test(tc_a, test_default36);
  tcase_add_test(tc_a, test_default37);
  tcase_add_test(tc_a, test_default38);
  tcase_add_test(tc_a, test_default39);
  tcase_add_test(tc_a, test_default40);
  tcase_add_test(tc_a, test_default41);
  tcase_add_test(tc_a, test_default42);
  tcase_add_test(tc_a, test_default43);
  tcase_add_test(tc_a, test_default44);
  tcase_add_test(tc_a, test_default45);
  tcase_add_test(tc_a, test_default46);
  tcase_add_test(tc_a, test_default47);
  tcase_add_test(tc_a, test_default48);
  tcase_add_test(tc_a, test_default49);
  tcase_add_test(tc_a, test_default50);
  tcase_add_test(tc_a, test_default51);
  tcase_add_test(tc_a, test_default52);
  tcase_add_test(tc_a, test_default53);
  tcase_add_test(tc_a, test_default54);
  tcase_add_test(tc_a, test_default55);
  tcase_add_test(tc_a, test_default56);
  tcase_add_test(tc_a, test_default57);
  tcase_add_test(tc_a, test_default58);
  tcase_add_test(tc_a, test_default59);
  tcase_add_test(tc_a, test_default60);
  tcase_add_test(tc_a, test_default61);
  tcase_add_test(tc_a, test_default62);
  tcase_add_test(tc_a, test_default63);
  tcase_add_test(tc_a, test_default64);
  tcase_add_test(tc_a, test_default65);
  tcase_add_test(tc_a, test_default66);
  tcase_add_test(tc_a, test_default67);
  tcase_add_test(tc_a, test_default68);
  tcase_add_test(tc_a, test_default69);
  tcase_add_test(tc_a, test_default70);
  tcase_add_test(tc_a, test_default71);
  tcase_add_test(tc_a, test_default72);
  tcase_add_test(tc_a, test_default73);
  tcase_add_test(tc_a, test_default74);
  tcase_add_test(tc_a, test_default75);
  tcase_add_test(tc_a, test_default76);
  tcase_add_test(tc_a, test_default77);
  tcase_add_test(tc_a, test_default78);
  tcase_add_test(tc_a, test_default79);
  tcase_add_test(tc_a, test_default80);
  tcase_add_test(tc_a, test_default81);
  tcase_add_test(tc_a, test_default82);
  tcase_add_test(tc_a, test_default83);
  tcase_add_test(tc_a, test_default84);
  tcase_add_test(tc_a, test_default85);
  tcase_add_test(tc_a, test_default86);
  tcase_add_test(tc_a, test_default87);
  tcase_add_test(tc_a, test_default88);
  tcase_add_test(tc_a, test_default89);
  tcase_add_test(tc_a, test_default90);
  tcase_add_test(tc_a, test_default91);
  tcase_add_test(tc_a, test_default92);
  tcase_add_test(tc_a, test_default93);
  tcase_add_test(tc_a, test_default94);
  tcase_add_test(tc_a, test_default95);
  tcase_add_test(tc_a, test_default96);
  tcase_add_test(tc_a, test_default97);
  tcase_add_test(tc_a, test_default98);
  tcase_add_test(tc_a, test_default99);
  tcase_add_test(tc_a, test_default100);
  tcase_add_test(tc_a, test_default101);
  tcase_add_test(tc_a, test_default102);
  tcase_add_test(tc_a, test_default103);
  tcase_add_test(tc_a, test_default104);
  tcase_add_test(tc_a, test_default105);
  tcase_add_test(tc_a, test_default106);
  tcase_add_test(tc_a, test_default107);
  tcase_add_test(tc_a, test_default108);
  tcase_add_test(tc_a, test_default109);
  tcase_add_test(tc_a, test_default110);
  tcase_add_test(tc_a, test_default111);
  tcase_add_test(tc_a, test_default112);
  tcase_add_test(tc_a, test_default113);
  tcase_add_test(tc_a, test_default115);
  tcase_add_test(tc_a, test_default116);
  tcase_add_test(tc_a, test_default117);
  tcase_add_test(tc_a, test_default118);
  tcase_add_test(tc_a, test_default119);
  tcase_add_test(tc_a, test_default120);
  tcase_add_test(tc_a, test_default122);
  tcase_add_test(tc_a, test_default123);
  tcase_add_test(tc_a, test_default124);
  tcase_add_test(tc_a, test_default125);
  tcase_add_test(tc_a, test_default126);
  tcase_add_test(tc_a, test_default127);
  tcase_add_test(tc_a, test_default128);
  tcase_add_test(tc_a, test_default129);
  tcase_add_test(tc_a, test_default130);
  tcase_add_test(tc_a, test_default131);
  tcase_add_test(tc_a, test_default132);
  tcase_add_test(tc_a, test_default133);
  tcase_add_test(tc_a, test_default134);
  tcase_add_test(tc_a, test_default135);
  tcase_add_test(tc_a, test_default136);
  tcase_add_test(tc_a, test_default137);
  tcase_add_test(tc_a, test_default138);
  tcase_add_test(tc_a, test_default139);
  tcase_add_test(tc_a, test_default140);
  tcase_add_test(tc_a, string);
  tcase_add_test(tc_a, string_precision);
  tcase_add_test(tc_a, string_width);
  tcase_add_test(tc_a, string_flags);
  tcase_add_test(tc_a, string_long);
  tcase_add_test(tc_a, string_many);
  tcase_add_test(tc_a, string_width_huge);
  tcase_add_test(tc_a, test_one_string);
  tcase_add_test(tc_a, test_many_string);
  tcase_add_test(tc_a, wstr);
  tcase_add_test(tc_a, wstr1);
  tcase_add_test(tc_a, wstr2);
  tcase_add_test(tc_a, wstr3);
  tcase_add_test(tc_a, wstr4);
  tcase_add_test(tc_a, wchr2);
  tcase_add_test(tc_a, wchr);
  tcase_add_test(tc_a, width_char);
  tcase_add_test(tc_a, minus_wchr);
  tcase_add_test(tc_a, float_precision);
  tcase_add_test(tc_a, float_width);
  tcase_add_test(tc_a, float_precision_zero);
  tcase_add_test(tc_a, float_precision_empty);
  tcase_add_test(tc_a, float_precision_huge);
  tcase_add_test(tc_a, float_precision_huge_negative);
  tcase_add_test(tc_a, float_huge);
  tcase_add_test(tc_a, float_flags);
  tcase_add_test(tc_a, float_many);
  tcase_add_test(tc_a, test_one_float);
  tcase_add_test(tc_a, test_many_float);
  tcase_add_test(tc_a, test_default_multy);
  tcase_add_test(tc_a, test_no_args);
  tcase_add_test(tc_a, test_format_d);
  tcase_add_test(tc_a, test_flag_minus);
  tcase_add_test(tc_a, memchr_test);
  tcase_add_test(tc_a, memcmp_test);
  tcase_add_test(tc_a, memcpy_test);
  tcase_add_test(tc_a, memmove_test);
  tcase_add_test(tc_a, memset_test);
  tcase_add_test(tc_a, strcat_test);
  tcase_add_test(tc_a, strncat_test);
  tcase_add_test(tc_a, strchr_test);
  tcase_add_test(tc_a, strcmp_test);
  tcase_add_test(tc_a, strncmp_test);
  tcase_add_test(tc_a, strcpy_test);
  tcase_add_test(tc_a, strncpy_test);
  tcase_add_test(tc_a, strcspn_test);
  tcase_add_test(tc_a, strlen_test);
  tcase_add_test(tc_a, strpbrk_test);
  tcase_add_test(tc_a, strrchr_test);
  tcase_add_test(tc_a, strspn_test);
  tcase_add_test(tc_a, strstr_test);
  tcase_add_test(tc_a, to_upper_test);
  tcase_add_test(tc_a, to_lower_test);
  tcase_add_test(tc_a, insert_test);
  tcase_add_test(tc_a, test_trim_1);
  tcase_add_test(tc_a, test_trim_2);
  tcase_add_test(tc_a, test_trim_3);
  tcase_add_test(tc_a, test_trim_4);
  tcase_add_test(tc_a, test_trim_5);
  tcase_add_test(tc_a, test_trim_6);
  tcase_add_test(tc_a, test_trim_7);
  tcase_add_test(tc_a, test_trim_8);
  tcase_add_test(tc_a, test_trim_9);
  tcase_add_test(tc_a, test_trim_10);
  tcase_add_test(tc_a, strerror_test);
  tcase_add_test(tc_a, strtok_test);
  tcase_add_test(tc_a, sprintf_percent);
  tcase_add_test(tc_a, sprintf_d);
  tcase_add_test(tc_a, sprintf_c);
  tcase_add_test(tc_a, sprintf_s);
  tcase_add_test(tc_a, test_char_default);
  tcase_add_test(tc_a, test_char_multy);
  tcase_add_test(tc_a, test_memchr);
  tcase_add_test(tc_a, test_memcmp);
  tcase_add_test(tc_a, test_memcpy);
  tcase_add_test(tc_a, test_memmove);
  tcase_add_test(tc_a, test_memset);
  tcase_add_test(tc_a, test_strcat);
  tcase_add_test(tc_a, test_strlen);
  tcase_add_test(tc_a, test_strcmp);
  tcase_add_test(tc_a, test_strcpy);
  tcase_add_test(tc_a, test_strchr);
  tcase_add_test(tc_a, test_strstr);
  tcase_add_test(tc_a, test_strtok);
  tcase_add_test(tc_a, test_sscanf_int);
  tcase_add_test(tc_a, test_sscanf_float);
  tcase_add_test(tc_a, test_sscanf_string);
  tcase_add_test(tc_a, test_sscanf_skip_whitespaces);
  tcase_add_test(tc_a, test_sscanf_mixed_type);
  tcase_add_test(tc_a, test_sscanf_width_specifier);
  tcase_add_test(tc_a, test_sscanf_n_assignment);
  tcase_add_test(tc_a, test_sscanf_spec_i_int1);
  tcase_add_test(tc_a, test_sscanf_spec_i_int2);
  tcase_add_test(tc_a, test_sscanf_spec_i_int3);
  tcase_add_test(tc_a, test_sscanf_oct);
  tcase_add_test(tc_a, test_sscanf_hex);
  tcase_add_test(tc_a, s21_sscanf_test_17_o_option);
  tcase_add_test(tc_a, s21_sscanf_test_18_o_option);
  tcase_add_test(tc_a, s21_sscanf_test_19_u_option);
  tcase_add_test(tc_a, test_strtold_exp);
  tcase_add_test(tc_a, test_s21_isdigit_valid);
  tcase_add_test(tc_a, test_s21_isdigit_invalid);
  tcase_add_test(tc_a, test_s21_strntollu_valid);

  // Добавляем кейсы в сьют
  suite_add_tcase(s, tc_a);

  return s;
}

int main() {
  setlocale(LC_ALL, "");
  setlocale(LC_NUMERIC, "C");
  int number_failed;
  Suite *s;
  SRunner *sr;

  s = s21_sprintf_suite();
  sr = srunner_create(s);

  // srunner_run_all(sr, CK_NORMAL);  //?
  for (int repeats = 0; repeats < 1; repeats++) srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
