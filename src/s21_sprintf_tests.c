#include <check.h>
#include <stdio.h>
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

START_TEST(test_default_multy) {
    char result[20];
    char assert[20];
    s21_sprintf(result, "Count: %+d%d%d%d", -4, 8, 15, 16);
    sprintf(assert, "Count: 2 %d%d%d%d", -4, 8, 15, 16);
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