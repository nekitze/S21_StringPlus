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
    s21_sprintf(result, "Count: %*c", c, c);
    sprintf(assert, "Count: %*c", c, c);
    ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default8) {
    char result[20];
    char assert[20];
    int d = 57;
    s21_sprintf(result, "Count: %d 1", d);
    sprintf(assert, "Count: %d 1", d);
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