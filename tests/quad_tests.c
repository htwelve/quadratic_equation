#include <check.h>

#include "../src/quadratic_equation.h"
#define TOLERANCE 1e-6

START_TEST(quad_standart) {
  double expected_x1 = 1.618033988749895;
  double expected_x2 = -0.6180339887498949;
  int expected_return = QUAD_TWO_SOLUTIONS;
  double a = -5;
  double b = 5;
  double c = 5;
  double x1 = 0;
  double x2 = 0;
  int func_return = solve_equation(a, b, c, &x1, &x2);
  ck_assert_double_eq_tol(x1, expected_x1, TOLERANCE);
  ck_assert_double_eq_tol(x2, expected_x2, TOLERANCE);
  ck_assert_int_eq(func_return, expected_return);
}
END_TEST

START_TEST(quad_standart2) {
  double expected_x1 = -5.8920655280137;
  double expected_x2 = -1.7035388675906964;
  int expected_return = QUAD_TWO_SOLUTIONS;
  double a = 45.5;
  double b = 345.6;
  double c = 456.7;
  double x1 = 0;
  double x2 = 0;
  int func_return = solve_equation(a, b, c, &x1, &x2);
  ck_assert_double_eq_tol(x1, expected_x1, TOLERANCE);
  ck_assert_double_eq_tol(x2, expected_x2, TOLERANCE);
  ck_assert_int_eq(func_return, expected_return);
}
END_TEST

START_TEST(negative_discriminant) {
  double expected_x1 = 0;
  double expected_x2 = 0;
  int expected_return = QUAD_NO_SOLUTIONS;
  double a = 5;
  double b = 5;
  double c = 5;
  double x1 = 0;
  double x2 = 0;
  int func_return = solve_equation(a, b, c, &x1, &x2);
  ck_assert_double_eq_tol(x1, expected_x1, TOLERANCE);
  ck_assert_double_eq_tol(x2, expected_x2, TOLERANCE);
  ck_assert_int_eq(func_return, expected_return);
}
END_TEST

START_TEST(zero_a) {
  double expected_x1 = -1;
  double expected_x2 = -1;
  int expected_return = QUAD_ONE_SOLUTION;
  double a = 0;
  double b = 5;
  double c = 5;
  double x1 = 0;
  double x2 = 0;
  int func_return = solve_equation(a, b, c, &x1, &x2);
  ck_assert_double_eq_tol(x1, expected_x1, TOLERANCE);
  ck_assert_double_eq_tol(x2, expected_x2, TOLERANCE);
  ck_assert_int_eq(func_return, expected_return);
}
END_TEST

START_TEST(zero_a_zero_c) {
  double expected_x1 = 0;
  double expected_x2 = 0;
  int expected_return = QUAD_ONE_SOLUTION;
  double a = 0;
  double b = 5;
  double c = 0;
  double x1 = 0;
  double x2 = 0;
  int func_return = solve_equation(a, b, c, &x1, &x2);
  ck_assert_double_eq_tol(x1, expected_x1, TOLERANCE);
  ck_assert_double_eq_tol(x2, expected_x2, TOLERANCE);
  ck_assert_int_eq(func_return, expected_return);
}
END_TEST

START_TEST(zero_b_negative_c) {
  double expected_x1 = 1;
  double expected_x2 = -1;
  int expected_return = QUAD_TWO_SOLUTIONS;
  double a = 5;
  double b = 0;
  double c = -5;
  double x1 = 0;
  double x2 = 0;
  int func_return = solve_equation(a, b, c, &x1, &x2);
  ck_assert_double_eq_tol(x1, expected_x1, TOLERANCE);
  ck_assert_double_eq_tol(x2, expected_x2, TOLERANCE);
  ck_assert_int_eq(func_return, expected_return);
}
END_TEST

START_TEST(zero_discrminant) {
  double expected_x1 = -1;
  double expected_x2 = -1;
  int expected_return = QUAD_ONE_SOLUTION;
  double a = 5;
  double b = 10;
  double c = 5;
  double x1 = 0;
  double x2 = 0;
  int func_return = solve_equation(a, b, c, &x1, &x2);
  ck_assert_double_eq_tol(x1, expected_x1, TOLERANCE);
  ck_assert_double_eq_tol(x2, expected_x2, TOLERANCE);
  ck_assert_int_eq(func_return, expected_return);
}
END_TEST

START_TEST(NAN_args) {
  double expected_x1 = 0;
  double expected_x2 = 0;
  int expected_return = QUAD_ERROR;
  double a = 5;
  double b = nan("");
  double c = 5;
  double x1 = 0;
  double x2 = 0;
  int func_return = solve_equation(a, b, c, &x1, &x2);
  ck_assert_double_eq_tol(x1, expected_x1, TOLERANCE);
  ck_assert_double_eq_tol(x2, expected_x2, TOLERANCE);
  ck_assert_int_eq(func_return, expected_return);
}
END_TEST

START_TEST(NULL_pointer) {
  double expected_x1 = 0;
  int expected_return = QUAD_ERROR;
  double a = 5;
  double b = 10;
  double c = 5;
  double x1 = 0;
  int func_return = solve_equation(a, b, c, &x1, NULL);
  ck_assert_double_eq_tol(x1, expected_x1, TOLERANCE);
  ck_assert_int_eq(func_return, expected_return);
}
END_TEST

START_TEST(inf_args) {
  double expected_x1 = 0;
  double expected_x2 = 0;
  int expected_return = QUAD_ERROR;
  double a = INFINITY;
  double b = -INFINITY;
  double c = INFINITY;
  double x1 = 0;
  double x2 = 0;
  int func_return = solve_equation(a, b, c, &x1, NULL);
  ck_assert_double_eq_tol(x1, expected_x1, TOLERANCE);
  ck_assert_double_eq_tol(x2, expected_x2, TOLERANCE);
  ck_assert_int_eq(func_return, expected_return);
}
END_TEST

void case_test(Suite *s, int *fail) {
  SRunner *runner = srunner_create(s);
  srunner_run_all(runner, CK_NORMAL);
  *fail = srunner_ntests_failed(runner);
  srunner_free(runner);
}

Suite *quadratic_suite(void) {
  Suite *s1;
  TCase *tc_core;
  s1 = suite_create("quadratic_suite");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, quad_standart);
  tcase_add_test(tc_core, quad_standart2);
  tcase_add_test(tc_core, negative_discriminant);
  tcase_add_test(tc_core, zero_a);
  tcase_add_test(tc_core, zero_a_zero_c);
  tcase_add_test(tc_core, zero_b_negative_c);
  tcase_add_test(tc_core, zero_discrminant);
  tcase_add_test(tc_core, NAN_args);
  tcase_add_test(tc_core, NULL_pointer);
  tcase_add_test(tc_core, inf_args);
  suite_add_tcase(s1, tc_core);
  return s1;
}

int main() {
  int fail = 0;
  case_test(quadratic_suite(), &fail);
  return fail;
}