#include "ll.h"
#include <check.h>
#include <stdbool.h>

START_TEST(test_ll_new)
{
  ll_t *ll = NULL;

  ck_assert_ptr_ne(ll = ll_new(), NULL);
  ck_assert(ll_is_empty(ll));
  ll_destroy(ll);
}
END_TEST

START_TEST(test_ll_push_tail)
{
  ll_t *ll = NULL;

  ck_assert_ptr_ne(ll = ll_new(), NULL);
  ck_assert(ll_is_empty(ll));
  ck_assert(ll_push_tail(ll, "first"));
  ck_assert(!ll_is_empty(ll));
  ll_destroy(ll);
}
END_TEST

START_TEST(test_ll_pop_head_empty)
{
  ll_t *ll = NULL;

  ck_assert_ptr_ne(ll = ll_new(), NULL);
  ck_assert(ll_is_empty(ll));
  ck_assert_ptr_eq(ll_pop_head(ll), NULL);
  ck_assert(ll_is_empty(ll));
  ll_destroy(ll);
}
END_TEST

START_TEST(test_ll_push_tail_pop_head)
{
  ll_t *ll = NULL;

  ck_assert_ptr_ne(ll = ll_new(), NULL);
  ck_assert(ll_is_empty(ll));
  ck_assert(ll_push_tail(ll, "first"));
  ck_assert(!ll_is_empty(ll));
  ck_assert_str_eq(ll_pop_head(ll), "first");
  ck_assert(ll_is_empty(ll));
  ll_destroy(ll);
}
END_TEST

START_TEST(test_ll_push_2_tail_pop_2_head)
{
  ll_t *ll = NULL;

  ck_assert_ptr_ne(ll = ll_new(), NULL);
  ck_assert(ll_is_empty(ll));
  ck_assert(ll_push_tail(ll, "first"));
  ck_assert(ll_push_tail(ll, "second"));
  ck_assert(!ll_is_empty(ll));
  ck_assert_str_eq(ll_pop_head(ll), "first");
  ck_assert(!ll_is_empty(ll));
  ck_assert_str_eq(ll_pop_head(ll), "second");
  ck_assert(ll_is_empty(ll));
  ll_destroy(ll);
}
END_TEST

START_TEST(test_ll_push_2_tail_pop_1_head)
{
  ll_t *ll = NULL;

  ck_assert_ptr_ne(ll = ll_new(), NULL);
  ck_assert(ll_is_empty(ll));
  ck_assert(ll_push_tail(ll, "first"));
  ck_assert(ll_push_tail(ll, "second"));
  ck_assert(!ll_is_empty(ll));
  ck_assert_str_eq(ll_pop_head(ll), "first");
  ck_assert(!ll_is_empty(ll));
  ll_destroy(ll);
}
END_TEST

START_TEST(test_ll_push_head)
{
  ll_t *ll = NULL;

  ck_assert_ptr_ne(ll = ll_new(), NULL);
  ck_assert(ll_is_empty(ll));
  ck_assert(ll_push_head(ll, "first"));
  ck_assert(!ll_is_empty(ll));
  ll_destroy(ll);
}
END_TEST

START_TEST(test_ll_push_head_pop_head)
{
  ll_t *ll = NULL;

  ck_assert_ptr_ne(ll = ll_new(), NULL);
  ck_assert(ll_is_empty(ll));
  ck_assert(ll_push_head(ll, "first"));
  ck_assert(!ll_is_empty(ll));
  ck_assert_str_eq(ll_pop_head(ll), "first");
  ck_assert(ll_is_empty(ll));
  ll_destroy(ll);
}
END_TEST

START_TEST(test_ll_push_2_head_pop_2_head)
{
  ll_t *ll = NULL;

  ck_assert_ptr_ne(ll = ll_new(), NULL);
  ck_assert(ll_is_empty(ll));
  ck_assert(ll_push_head(ll, "first"));
  ck_assert(!ll_is_empty(ll));
  ck_assert(ll_push_head(ll, "second"));
  ck_assert(!ll_is_empty(ll));
  ck_assert_str_eq(ll_pop_head(ll), "second");
  ck_assert(!ll_is_empty(ll));
  ck_assert_str_eq(ll_pop_head(ll), "first");
  ck_assert(ll_is_empty(ll));
  ll_destroy(ll);
}
END_TEST

START_TEST(test_ll_push_2_head_pop_1_head)
{
  ll_t *ll = NULL;

  ck_assert_ptr_ne(ll = ll_new(), NULL);
  ck_assert(ll_is_empty(ll));
  ck_assert(ll_push_head(ll, "first"));
  ck_assert(!ll_is_empty(ll));
  ck_assert(ll_push_head(ll, "second"));
  ck_assert(!ll_is_empty(ll));
  ck_assert_str_eq(ll_pop_head(ll), "second");
  ck_assert(!ll_is_empty(ll));
  ll_destroy(ll);
}
END_TEST

START_TEST(test_ll_push_1_head_pop_2_head)
{
  ll_t *ll = NULL;

  ck_assert_ptr_ne(ll = ll_new(), NULL);
  ck_assert(ll_is_empty(ll));
  ck_assert(ll_push_head(ll, "first"));
  ck_assert(!ll_is_empty(ll));
  ck_assert_str_eq(ll_pop_head(ll), "first");
  ck_assert(ll_is_empty(ll));
  ck_assert_ptr_eq(ll_pop_head(ll), NULL);
  ck_assert(ll_is_empty(ll));
  ll_destroy(ll);
}
END_TEST

START_TEST(test_ll_push_1_tail_pop_2_head)
{
  ll_t *ll = NULL;

  ck_assert_ptr_ne(ll = ll_new(), NULL);
  ck_assert(ll_is_empty(ll));
  ck_assert(ll_push_tail(ll, "first"));
  ck_assert(!ll_is_empty(ll));
  ck_assert_str_eq(ll_pop_head(ll), "first");
  ck_assert(ll_is_empty(ll));
  ck_assert_ptr_eq(ll_pop_head(ll), NULL);
  ck_assert(ll_is_empty(ll));
  ll_destroy(ll);
}
END_TEST

START_TEST(test_ll_push_head_get_head)
{
  ll_t *ll = NULL;
  ll_node_t *node = NULL;

  ck_assert_ptr_ne(ll = ll_new(), NULL);
  ck_assert(ll_is_empty(ll));
  ck_assert(ll_push_head(ll, "first"));
  ck_assert(!ll_is_empty(ll));
  ck_assert_ptr_ne(node = ll_get_head(ll), NULL);
  ck_assert(!ll_is_empty(ll));
  ck_assert_str_eq(ll_node_get(node), "first");
  ll_destroy(ll);
}
END_TEST

START_TEST(test_ll_push_tail_get_head)
{
  ll_t *ll = NULL;
  ll_node_t *node = NULL;

  ck_assert_ptr_ne(ll = ll_new(), NULL);
  ck_assert(ll_is_empty(ll));
  ck_assert(ll_push_tail(ll, "first"));
  ck_assert(!ll_is_empty(ll));
  ck_assert_ptr_ne(node = ll_get_head(ll), NULL);
  ck_assert(!ll_is_empty(ll));
  ck_assert_str_eq(ll_node_get(node), "first");
  ll_destroy(ll);
}
END_TEST

START_TEST(test_ll_push_2_head_get_all)
{
  ll_t *ll = NULL;
  ll_node_t *node = NULL;

  ck_assert_ptr_ne(ll = ll_new(), NULL);
  ck_assert(ll_is_empty(ll));
  ck_assert(ll_push_head(ll, "first"));
  ck_assert(!ll_is_empty(ll));
  ck_assert_ptr_ne(node = ll_get_head(ll), NULL);
  ck_assert(!ll_is_empty(ll));
  ck_assert_str_eq(ll_node_get(node), "first");
  ck_assert(ll_push_head(ll, "second"));
  ck_assert(!ll_is_empty(ll));
  ck_assert_ptr_ne(node = ll_get_head(ll), NULL);
  ck_assert(!ll_is_empty(ll));
  ck_assert_str_eq(ll_node_get(node), "second");
  ck_assert_ptr_ne(node = ll_node_next(node), NULL);
  ck_assert(!ll_is_empty(ll));
  ck_assert_str_eq(ll_node_get(node), "first");
  ck_assert_ptr_eq(node = ll_node_next(node), NULL);
  ll_destroy(ll);
}
END_TEST

START_TEST(test_ll_push_2_tail_get_all)
{
  ll_t *ll = NULL;
  ll_node_t *node = NULL;

  ck_assert_ptr_ne(ll = ll_new(), NULL);
  ck_assert(ll_is_empty(ll));
  ck_assert(ll_push_tail(ll, "first"));
  ck_assert(!ll_is_empty(ll));
  ck_assert_ptr_ne(node = ll_get_head(ll), NULL);
  ck_assert(!ll_is_empty(ll));
  ck_assert_str_eq(ll_node_get(node), "first");
  ck_assert(ll_push_tail(ll, "second"));
  ck_assert(!ll_is_empty(ll));
  ck_assert_ptr_ne(node = ll_node_next(node), NULL);
  ck_assert(!ll_is_empty(ll));
  ck_assert_str_eq(ll_node_get(node), "second");
  ck_assert_ptr_eq(node = ll_node_next(node), NULL);
  ll_destroy(ll);
}
END_TEST

START_TEST(test_ll_push_head_push_tail_get_all)
{
  ll_t *ll = NULL;
  ll_node_t *node = NULL;

  ck_assert_ptr_ne(ll = ll_new(), NULL);
  ck_assert(ll_is_empty(ll));
  ck_assert(ll_push_head(ll, "first"));
  ck_assert(!ll_is_empty(ll));
  ck_assert_ptr_ne(node = ll_get_head(ll), NULL);
  ck_assert(!ll_is_empty(ll));
  ck_assert_str_eq(ll_node_get(node), "first");
  ck_assert(ll_push_tail(ll, "second"));
  ck_assert(!ll_is_empty(ll));
  ck_assert_ptr_ne(node = ll_node_next(node), NULL);
  ck_assert(!ll_is_empty(ll));
  ck_assert_str_eq(ll_node_get(node), "second");
  ck_assert_ptr_eq(node = ll_node_next(node), NULL);
  ll_destroy(ll);
}
END_TEST

START_TEST(test_ll_push_tail_push_head_get_all)
{
  ll_t *ll = NULL;
  ll_node_t *node = NULL;

  ck_assert_ptr_ne(ll = ll_new(), NULL);
  ck_assert(ll_is_empty(ll));
  ck_assert(ll_push_tail(ll, "first"));
  ck_assert(!ll_is_empty(ll));
  ck_assert_ptr_ne(node = ll_get_head(ll), NULL);
  ck_assert(!ll_is_empty(ll));
  ck_assert_str_eq(ll_node_get(node), "first");
  ck_assert(ll_push_head(ll, "second"));
  ck_assert(!ll_is_empty(ll));
  ck_assert_ptr_ne(node = ll_get_head(ll), NULL);
  ck_assert(!ll_is_empty(ll));
  ck_assert_str_eq(ll_node_get(node), "second");
  ck_assert(!ll_is_empty(ll));
  ck_assert_ptr_ne(node = ll_node_next(node), NULL);
  ck_assert(!ll_is_empty(ll));
  ck_assert_str_eq(ll_node_get(node), "first");
  ck_assert_ptr_eq(node = ll_node_next(node), NULL);
  ll_destroy(ll);
}
END_TEST

START_TEST(test_ll_get_head_from_empty)
{
  ll_t *ll = NULL;

  ck_assert_ptr_ne(ll = ll_new(), NULL);
  ck_assert(ll_is_empty(ll));
  ck_assert_ptr_eq(ll_get_head(ll), NULL);
  ll_destroy(ll);
}
END_TEST

START_TEST(test_ll_iterate_from_null)
{
  ck_assert_ptr_eq(ll_node_next(NULL), NULL);
}
END_TEST

START_TEST(test_ll_push_7_tail_and_iterate)
{
  ll_t *ll = NULL;
  ll_node_t *node = NULL;

  ck_assert_ptr_ne(ll = ll_new(), NULL);
  ck_assert(ll_is_empty(ll));
  ck_assert(ll_push_tail(ll, "first"));
  ck_assert(!ll_is_empty(ll));
  ck_assert(ll_push_tail(ll, "second"));
  ck_assert(!ll_is_empty(ll));
  ck_assert(ll_push_tail(ll, "third"));
  ck_assert(!ll_is_empty(ll));
  ck_assert(ll_push_tail(ll, "fourth"));
  ck_assert(!ll_is_empty(ll));
  ck_assert(ll_push_tail(ll, "fifth"));
  ck_assert(!ll_is_empty(ll));
  ck_assert(ll_push_tail(ll, "sixth"));
  ck_assert(!ll_is_empty(ll));
  ck_assert(ll_push_tail(ll, "seventh"));
  ck_assert(!ll_is_empty(ll));
  ck_assert_ptr_ne(node = ll_get_head(ll), NULL);
  ck_assert_str_eq(ll_node_get(node), "first");
  ck_assert_ptr_ne(node = ll_node_next(node), NULL);
  ck_assert_str_eq(ll_node_get(node), "second");
  ck_assert_ptr_ne(node = ll_node_next(node), NULL);
  ck_assert_str_eq(ll_node_get(node), "third");
  ck_assert_ptr_ne(node = ll_node_next(node), NULL);
  ck_assert_str_eq(ll_node_get(node), "fourth");
  ck_assert_ptr_ne(node = ll_node_next(node), NULL);
  ck_assert_str_eq(ll_node_get(node), "fifth");
  ck_assert_ptr_ne(node = ll_node_next(node), NULL);
  ck_assert_str_eq(ll_node_get(node), "sixth");
  ck_assert_ptr_ne(node = ll_node_next(node), NULL);
  ck_assert_str_eq(ll_node_get(node), "seventh");
  ll_destroy(ll);
}
END_TEST

START_TEST(test_ll_push_7_head_and_iterate)
{
  ll_t *ll = NULL;
  ll_node_t *node = NULL;

  ck_assert_ptr_ne(ll = ll_new(), NULL);
  ck_assert(ll_is_empty(ll));
  ck_assert(ll_push_head(ll, "first"));
  ck_assert(!ll_is_empty(ll));
  ck_assert(ll_push_head(ll, "second"));
  ck_assert(!ll_is_empty(ll));
  ck_assert(ll_push_head(ll, "third"));
  ck_assert(!ll_is_empty(ll));
  ck_assert(ll_push_head(ll, "fourth"));
  ck_assert(!ll_is_empty(ll));
  ck_assert(ll_push_head(ll, "fifth"));
  ck_assert(!ll_is_empty(ll));
  ck_assert(ll_push_head(ll, "sixth"));
  ck_assert(!ll_is_empty(ll));
  ck_assert(ll_push_head(ll, "seventh"));
  ck_assert(!ll_is_empty(ll));
  ck_assert_ptr_ne(node = ll_get_head(ll), NULL);
  ck_assert_str_eq(ll_node_get(node), "seventh");
  ck_assert_ptr_ne(node = ll_node_next(node), NULL);
  ck_assert_str_eq(ll_node_get(node), "sixth");
  ck_assert_ptr_ne(node = ll_node_next(node), NULL);
  ck_assert_str_eq(ll_node_get(node), "fifth");
  ck_assert_ptr_ne(node = ll_node_next(node), NULL);
  ck_assert_str_eq(ll_node_get(node), "fourth");
  ck_assert_ptr_ne(node = ll_node_next(node), NULL);
  ck_assert_str_eq(ll_node_get(node), "third");
  ck_assert_ptr_ne(node = ll_node_next(node), NULL);
  ck_assert_str_eq(ll_node_get(node), "second");
  ck_assert_ptr_ne(node = ll_node_next(node), NULL);
  ck_assert_str_eq(ll_node_get(node), "first");
  ll_destroy(ll);
}
END_TEST

Suite *
ll_suite(void)
{
  Suite *s = NULL;
  TCase *tc_core = NULL;
  TCase *tc_nodes = NULL;

  s = suite_create("Linked list");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_ll_new);
  tcase_add_test(tc_core, test_ll_push_head);
  tcase_add_test(tc_core, test_ll_push_tail);
  tcase_add_test(tc_core, test_ll_pop_head_empty);
  tcase_add_test(tc_core, test_ll_push_head_pop_head);
  tcase_add_test(tc_core, test_ll_push_tail_pop_head);
  tcase_add_test(tc_core, test_ll_push_2_head_pop_2_head);
  tcase_add_test(tc_core, test_ll_push_2_tail_pop_2_head);
  tcase_add_test(tc_core, test_ll_push_2_head_pop_1_head);
  tcase_add_test(tc_core, test_ll_push_2_tail_pop_1_head);
  tcase_add_test(tc_core, test_ll_push_1_head_pop_2_head);
  tcase_add_test(tc_core, test_ll_push_1_tail_pop_2_head);
  suite_add_tcase(s, tc_core);

  tc_nodes = tcase_create("Nodes");
  tcase_add_test(tc_nodes, test_ll_push_head_get_head);
  tcase_add_test(tc_nodes, test_ll_push_tail_get_head);
  tcase_add_test(tc_nodes, test_ll_push_2_head_get_all);
  tcase_add_test(tc_nodes, test_ll_push_2_tail_get_all);
  tcase_add_test(tc_nodes, test_ll_push_head_push_tail_get_all);
  tcase_add_test(tc_nodes, test_ll_push_tail_push_head_get_all);
  tcase_add_test(tc_nodes, test_ll_get_head_from_empty);
  tcase_add_test(tc_nodes, test_ll_iterate_from_null);
  tcase_add_test(tc_nodes, test_ll_push_7_tail_and_iterate);
  tcase_add_test(tc_nodes, test_ll_push_7_head_and_iterate);
  suite_add_tcase(s, tc_nodes);

  return s;
}
