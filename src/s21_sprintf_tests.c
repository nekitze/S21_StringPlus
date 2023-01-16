#include <check.h>
#include <stdio.h>
#include <stdlib.h>
#include "s21_string.h"

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
    s21_sprintf(result, "Count: %5c", c);
    sprintf(assert, "Count: %5c", c);
    ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default4) {
    char result[20];
    char assert[20];
    char c = 'b';
    s21_sprintf(result, "Count: %-5c", c);
    sprintf(assert, "Count: %-5c", c);
    ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default5) {
    char result[20];
    char assert[20];
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

START_TEST(test_default7) { // need to fix '*'
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
    long long d = 574567168717984;
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

START_TEST(test_flag_minus) { // TO FIX
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
    s21_sprintf(result, "Count: %+10.5i end", i+1);
    sprintf(assert, "Count: %+10.5i end", i+1);
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
    s21_sprintf(str1, format, val);
    sprintf(str2, format, val);

    ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(float_width) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];
    char *format = "%10Lf";
    long double val = 15.35;
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

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
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(float_precision_huge) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];
    char *format = "%.15Lf";
    long double val = 15.35;
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(float_precision_huge_negative) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];
    char *format = "%.15Lf";
    long double val = -15.35581134;
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(float_huge) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];
    char *format = "%Lf";
    long double val = 72537572375.1431341;
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(float_flags) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];
    char *format = "% f";
    float val = 0;
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

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
    ck_assert_int_eq(
        s21_sprintf(str1, format, val, val1, val2, val3, val4, val5),
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

Suite * s21_sprintf_suite(void) {
    Suite *s;
    TCase *tc_s21_sprintf;

    // Создаём сьют
    s = suite_create("[s21_string] suite");

    // Создаём кейс
    tc_s21_sprintf = tcase_create("[s21_sprintf] case");
    
    // Добавялем тесты в кейс
    tcase_add_test(tc_s21_sprintf, test_default);
    tcase_add_test(tc_s21_sprintf, test_default2);
    tcase_add_test(tc_s21_sprintf, test_default3);
    tcase_add_test(tc_s21_sprintf, test_default4);
    tcase_add_test(tc_s21_sprintf, test_default5);
    tcase_add_test(tc_s21_sprintf, test_default6);
    tcase_add_test(tc_s21_sprintf, test_default7);
    tcase_add_test(tc_s21_sprintf, test_default8);
    tcase_add_test(tc_s21_sprintf, test_default9);
    tcase_add_test(tc_s21_sprintf, test_default10);
    tcase_add_test(tc_s21_sprintf, test_default11);
    tcase_add_test(tc_s21_sprintf, test_default12);
    tcase_add_test(tc_s21_sprintf, test_default13);
    tcase_add_test(tc_s21_sprintf, test_default14);
    tcase_add_test(tc_s21_sprintf, test_default15);
    tcase_add_test(tc_s21_sprintf, test_default16);
    tcase_add_test(tc_s21_sprintf, test_default17);
    tcase_add_test(tc_s21_sprintf, test_default18);
    tcase_add_test(tc_s21_sprintf, test_default19);
    tcase_add_test(tc_s21_sprintf, test_default20);
    tcase_add_test(tc_s21_sprintf, test_default21);
    tcase_add_test(tc_s21_sprintf, test_default22);
    tcase_add_test(tc_s21_sprintf, test_default23);
    tcase_add_test(tc_s21_sprintf, test_default24);
    tcase_add_test(tc_s21_sprintf, test_default25);
    tcase_add_test(tc_s21_sprintf, test_default26);
    tcase_add_test(tc_s21_sprintf, test_default27);
    tcase_add_test(tc_s21_sprintf, test_default28);
    tcase_add_test(tc_s21_sprintf, test_default29);
    tcase_add_test(tc_s21_sprintf, test_default30);
    tcase_add_test(tc_s21_sprintf, test_default31);
    tcase_add_test(tc_s21_sprintf, test_default32);
    tcase_add_test(tc_s21_sprintf, test_default33);
    tcase_add_test(tc_s21_sprintf, test_default34);
    tcase_add_test(tc_s21_sprintf, test_default35);
    tcase_add_test(tc_s21_sprintf, test_default36);
    tcase_add_test(tc_s21_sprintf, test_default37);
    tcase_add_test(tc_s21_sprintf, test_default38);
    tcase_add_test(tc_s21_sprintf, test_default39);
    tcase_add_test(tc_s21_sprintf, test_default40);
    tcase_add_test(tc_s21_sprintf, test_default41);
    tcase_add_test(tc_s21_sprintf, test_default42);
    tcase_add_test(tc_s21_sprintf, test_default43);
    tcase_add_test(tc_s21_sprintf, test_default44);
    tcase_add_test(tc_s21_sprintf, test_default45);
    tcase_add_test(tc_s21_sprintf, test_default46);
    tcase_add_test(tc_s21_sprintf, test_default47);
    tcase_add_test(tc_s21_sprintf, test_default48);
    tcase_add_test(tc_s21_sprintf, test_default49);
    tcase_add_test(tc_s21_sprintf, test_default50);
    tcase_add_test(tc_s21_sprintf, test_default51);
    tcase_add_test(tc_s21_sprintf, test_default52);
    tcase_add_test(tc_s21_sprintf, test_default53);
    tcase_add_test(tc_s21_sprintf, test_default54);
    tcase_add_test(tc_s21_sprintf, test_default55);
    tcase_add_test(tc_s21_sprintf, test_default56);
    tcase_add_test(tc_s21_sprintf, test_default57);
    tcase_add_test(tc_s21_sprintf, test_default58);
    tcase_add_test(tc_s21_sprintf, float_precision);
    tcase_add_test(tc_s21_sprintf, float_width);
    tcase_add_test(tc_s21_sprintf, float_precision_zero);
    tcase_add_test(tc_s21_sprintf, float_precision_empty);
    tcase_add_test(tc_s21_sprintf, float_precision_huge);
    tcase_add_test(tc_s21_sprintf, float_precision_huge_negative);
    tcase_add_test(tc_s21_sprintf, float_huge);
    tcase_add_test(tc_s21_sprintf, float_flags);
    tcase_add_test(tc_s21_sprintf, float_many);
    tcase_add_test(tc_s21_sprintf, test_one_float);
    tcase_add_test(tc_s21_sprintf, test_many_float);
    tcase_add_test(tc_s21_sprintf, test_default_multy);
    tcase_add_test(tc_s21_sprintf, test_no_args);
    tcase_add_test(tc_s21_sprintf, test_format_d);
    tcase_add_test(tc_s21_sprintf, test_flag_minus);
    // tcase_add_test(tc_s21_sprintf, str_to_int_test);
    tcase_add_test(tc_s21_sprintf, test_char_default);
    tcase_add_test(tc_s21_sprintf, test_char_multy);
    // tcase_add_test(tc_s21_sprintf, test_buffer_overflow);

    // Добавляем кейсы в сьют
    suite_add_tcase(s, tc_s21_sprintf);

    return s;
}

int main() {
    int number_failed;
    Suite *s;
    SRunner *sr;

    s = s21_sprintf_suite();
    sr = srunner_create(s);

    srunner_run_all(sr, CK_NORMAL); //?
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}