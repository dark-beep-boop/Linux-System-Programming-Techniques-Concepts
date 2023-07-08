#include "container.h"
#include "emp.h"
#include "gldll.h"
#include <check.h>

START_TEST(test_gldll_new)
{
  gldll_t *gldll = NULL;

  ck_assert_ptr_ne(gldll = gldll_new(), NULL);
  ck_assert(gldll_is_empty(gldll));
  gldll_destroy(gldll);
}
END_TEST

START_TEST(test_gldll_pop_head_from_empty)
{
  gldll_t *gldll = NULL;

  ck_assert_ptr_ne(gldll = gldll_new(), NULL);
  ck_assert(gldll_is_empty(gldll));
  ck_assert_ptr_eq(gldll_pop_head(gldll), NULL);
  ck_assert(gldll_is_empty(gldll));
  gldll_destroy(gldll);
}
END_TEST

START_TEST(test_gldll_push_head)
{
  gldll_t *gldll = NULL;
  emp_t *employee = NULL;

  ck_assert_ptr_ne(employee = emp_new(), NULL);
  emp_set_name(employee, "Neha");
  emp_set_salary(employee, 50000);
  emp_set_designation(employee, "HR");
  emp_set_id(employee, 21);

  ck_assert_ptr_ne(gldll = gldll_new(), NULL);
  ck_assert(gldll_is_empty(gldll));
  gldll_push_head(gldll, emp_get_glnode(employee));
  ck_assert(!gldll_is_empty(gldll));
  gldll_destroy(gldll);
}
END_TEST

START_TEST(test_gldll_push_head_pop_head)
{
  gldll_t *gldll = NULL;
  emp_t *employee = NULL;
  emp_t *popped_employee = NULL;
  gldll_node_t *node = NULL;

  ck_assert_ptr_ne(employee = emp_new(), NULL);
  emp_set_name(employee, "Neha");
  emp_set_salary(employee, 50000);
  emp_set_designation(employee, "HR");
  emp_set_id(employee, 21);

  ck_assert_ptr_ne(gldll = gldll_new(), NULL);
  ck_assert(gldll_is_empty(gldll));
  gldll_push_head(gldll, emp_get_glnode(employee));
  ck_assert(!gldll_is_empty(gldll));
  ck_assert_ptr_ne(node = gldll_pop_head(gldll), NULL);
  popped_employee = container_of(node, emp_t, glnode);
  ck_assert_ptr_eq(employee, popped_employee);
  ck_assert(gldll_is_empty(gldll));
  gldll_destroy(gldll);
  emp_destroy(employee);
}
END_TEST

START_TEST(test_gldll_push_2_head_pop_2_head)
{
  gldll_t *gldll = NULL;
  emp_t *employee1 = NULL;
  emp_t *employee2 = NULL;
  emp_t *popped_employee = NULL;
  gldll_node_t *node = NULL;

  ck_assert_ptr_ne(employee1 = emp_new(), NULL);
  emp_set_name(employee1, "Neha");
  emp_set_salary(employee1, 50000);
  emp_set_designation(employee1, "HR");
  emp_set_id(employee1, 21);

  ck_assert_ptr_ne(employee2 = emp_new(), NULL);
  emp_set_name(employee2, "Weeha");
  emp_set_salary(employee2, 70000);
  emp_set_designation(employee2, "D&R");
  emp_set_id(employee2, 9);

  ck_assert_ptr_ne(gldll = gldll_new(), NULL);
  ck_assert(gldll_is_empty(gldll));
  gldll_push_head(gldll, emp_get_glnode(employee1));
  gldll_push_head(gldll, emp_get_glnode(employee2));
  ck_assert(!gldll_is_empty(gldll));
  ck_assert_ptr_ne(node = gldll_pop_head(gldll), NULL);
  popped_employee = container_of(node, emp_t, glnode);
  ck_assert_ptr_eq(employee2, popped_employee);
  ck_assert(!gldll_is_empty(gldll));
  ck_assert_ptr_ne(node = gldll_pop_head(gldll), NULL);
  popped_employee = container_of(node, emp_t, glnode);
  ck_assert_ptr_eq(employee1, popped_employee);
  ck_assert(gldll_is_empty(gldll));
  gldll_destroy(gldll);
  emp_destroy(employee1);
  emp_destroy(employee2);
}
END_TEST

Suite *
gldll_suite(void)
{
  Suite *s = NULL;
  TCase *tc_core = NULL;

  s = suite_create("Glued doubly linked list");

  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, test_gldll_new);
  tcase_add_test(tc_core, test_gldll_pop_head_from_empty);
  tcase_add_test(tc_core, test_gldll_push_head);
  tcase_add_test(tc_core, test_gldll_push_head_pop_head);
  tcase_add_test(tc_core, test_gldll_push_2_head_pop_2_head);
  suite_add_tcase(s, tc_core);

  return s;
}
