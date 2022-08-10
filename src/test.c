#include "SmartCalc.h"
#include <check.h>

START_TEST(test_1) {
  double res = 0.0;
  char *str = "100*4+23-50/0.5+(123-112)";
  int error = 0;
  res = polish_notation(str, &error);
  ck_assert_int_eq(res, 334);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(test_2) {
  double res = 0.0;
  char *str =
      "+1-sin(1)-sin(1)+sin(1)-cos(1)+tan(1)-(cos(1)-cos(1))-sqrt(1)-2^2/"
      "(4+1-1*23*5/4/6)/((cos(1)+cos(2))/(1+2+3))/7";
  int error = 0;
  res = polish_notation(str, &error);
  ck_assert_int_eq(res, -132.377067);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(test_3) {
  double res = 0.0;
  char *str = "ln(35)*5-log(6)+sqrt(16)";
  int error = 0;
  res = polish_notation(str, &error);
  ck_assert_int_eq(res, 20.998589);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(test_4) {
  char *str = "(*)|(*))";
  int error = 0;
  polish_notation(str, &error);
  ck_assert_int_eq(error, 1);
}
END_TEST

START_TEST(test_5) {
  char *str = "(*)-(/)-(^)";
  int error = 0;
  polish_notation(str, &error);
  ck_assert_int_eq(error, 1);
}
END_TEST

START_TEST(test_6) {
  double res = 0.0;
  char *str = "acos(10mod3)+asin(1)+atan(1)";
  int error = 0;
  res = polish_notation(str, &error);
  ck_assert_int_eq(res, 2.356194);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(test_7) {
  char *str = "256.123.213 + 777";
  int error = 0;
  polish_notation(str, &error);
  ck_assert_int_eq(error, 1);
}
END_TEST

START_TEST(test_8) {
  double res = 0.0;
  char *str = "-10mod3";
  int error = 0;
  res = polish_notation(str, &error);
  ck_assert_int_eq(res, -1);
  ck_assert_int_eq(error, 0);
}
END_TEST

int main() {
  Suite *suite = suite_create("S21_TESTS");
  SRunner *srunner = srunner_create(suite);

  TCase *s21_calculation_1_case = tcase_create("calculation_1");
  suite_add_tcase(suite, s21_calculation_1_case);
  tcase_add_test(s21_calculation_1_case, test_1);

  TCase *s21_calculation_2_case = tcase_create("calculation_2");
  suite_add_tcase(suite, s21_calculation_2_case);
  tcase_add_test(s21_calculation_2_case, test_2);

  TCase *s21_calculation_3_case = tcase_create("calculation_3");
  suite_add_tcase(suite, s21_calculation_3_case);
  tcase_add_test(s21_calculation_3_case, test_3);

  TCase *s21_calculation_4_case = tcase_create("calculation_4");
  suite_add_tcase(suite, s21_calculation_4_case);
  tcase_add_test(s21_calculation_4_case, test_4);

  TCase *s21_calculation_5_case = tcase_create("calculation_5");
  suite_add_tcase(suite, s21_calculation_5_case);
  tcase_add_test(s21_calculation_5_case, test_5);

  TCase *s21_calculation_6_case = tcase_create("calculation_6");
  suite_add_tcase(suite, s21_calculation_6_case);
  tcase_add_test(s21_calculation_6_case, test_6);

  TCase *s21_calculation_7_case = tcase_create("calculation_7");
  suite_add_tcase(suite, s21_calculation_7_case);
  tcase_add_test(s21_calculation_7_case, test_7);

  TCase *s21_calculation_8_case = tcase_create("calculation_8");
  suite_add_tcase(suite, s21_calculation_8_case);
  tcase_add_test(s21_calculation_8_case, test_8);

  srunner_run_all(srunner, CK_VERBOSE);
  int number_failed = srunner_ntests_failed(srunner);
  srunner_free(srunner);

  return (number_failed == 0) ? 0 : 1;
}
