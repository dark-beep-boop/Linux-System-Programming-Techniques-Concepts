#include "emp.h"
#include "gldll.h"
#include <check.h>

START_TEST(test_gldll_new)
{
  gldll_t *gldll = NULL;

  ck_assert_ptr_ne(gldll = gldll_new(), NULL);
  ck_assert(gldll_is_empty(gldll));
  gldll_destroy(gldll);

  gldll = NULL;
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

  gldll = NULL;
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

  gldll = NULL;
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
  tcase_add_test(tc_core, test_gldll_push_head);
  suite_add_tcase(s, tc_core);

  return s;
}
