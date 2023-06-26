#include "dll.h"
#include <check.h>
#include <stdbool.h>
#include <stdio.h>

START_TEST(test_dll_new)
{
  dll_t *dll = NULL;

  ck_assert_ptr_ne(dll = dll_new(), NULL);
  ck_assert(dll_is_empty(dll));
  dll_destroy(dll);
}
END_TEST

START_TEST(test_dll_push_tail)
{
  dll_t *dll = NULL;

  ck_assert_ptr_ne(dll = dll_new(), NULL);
  ck_assert(dll_is_empty(dll));
  ck_assert(dll_push_tail(dll, "first"));
  ck_assert(!dll_is_empty(dll));
  dll_destroy(dll);
}
END_TEST

START_TEST(test_dll_pop_head_empty)
{
  dll_t *dll = NULL;

  ck_assert_ptr_ne(dll = dll_new(), NULL);
  ck_assert(dll_is_empty(dll));
  ck_assert_ptr_eq(dll_pop_head(dll), NULL);
  ck_assert(dll_is_empty(dll));
  dll_destroy(dll);
}
END_TEST

START_TEST(test_dll_pop_tail_empty)
{
  dll_t *dll = NULL;

  ck_assert_ptr_ne(dll = dll_new(), NULL);
  ck_assert(dll_is_empty(dll));
  ck_assert_ptr_eq(dll_pop_tail(dll), NULL);
  ck_assert(dll_is_empty(dll));
  dll_destroy(dll);
}
END_TEST

START_TEST(test_dll_push_tail_pop_head)
{
  dll_t *dll = NULL;

  ck_assert_ptr_ne(dll = dll_new(), NULL);
  ck_assert(dll_is_empty(dll));
  ck_assert(dll_push_tail(dll, "first"));
  ck_assert(!dll_is_empty(dll));
  ck_assert_str_eq(dll_pop_head(dll), "first");
  ck_assert(dll_is_empty(dll));
  dll_destroy(dll);
}
END_TEST

START_TEST(test_dll_push_head_pop_tail)
{
  dll_t *dll = NULL;

  ck_assert_ptr_ne(dll = dll_new(), NULL);
  ck_assert(dll_is_empty(dll));
  ck_assert(dll_push_head(dll, "first"));
  ck_assert(!dll_is_empty(dll));
  ck_assert_str_eq(dll_pop_tail(dll), "first");
  ck_assert(dll_is_empty(dll));
  dll_destroy(dll);
}
END_TEST

START_TEST(test_dll_push_tail_pop_tail)
{
  dll_t *dll = NULL;

  ck_assert_ptr_ne(dll = dll_new(), NULL);
  ck_assert(dll_is_empty(dll));
  ck_assert(dll_push_tail(dll, "first"));
  ck_assert(!dll_is_empty(dll));
  ck_assert_str_eq(dll_pop_tail(dll), "first");
  ck_assert(dll_is_empty(dll));
  dll_destroy(dll);
}
END_TEST

START_TEST(test_dll_push_2_tail_pop_2_head)
{
  dll_t *dll = NULL;

  ck_assert_ptr_ne(dll = dll_new(), NULL);
  ck_assert(dll_is_empty(dll));
  ck_assert(dll_push_tail(dll, "first"));
  ck_assert(dll_push_tail(dll, "second"));
  ck_assert(!dll_is_empty(dll));
  ck_assert_str_eq(dll_pop_head(dll), "first");
  ck_assert(!dll_is_empty(dll));
  ck_assert_str_eq(dll_pop_head(dll), "second");
  ck_assert(dll_is_empty(dll));
  dll_destroy(dll);
}
END_TEST

START_TEST(test_dll_push_2_head_pop_2_tail)
{
  dll_t *dll = NULL;

  ck_assert_ptr_ne(dll = dll_new(), NULL);
  ck_assert(dll_is_empty(dll));
  ck_assert(dll_push_head(dll, "first"));
  ck_assert(dll_push_head(dll, "second"));
  ck_assert(!dll_is_empty(dll));
  ck_assert_str_eq(dll_pop_tail(dll), "first");
  ck_assert(!dll_is_empty(dll));
  ck_assert_str_eq(dll_pop_tail(dll), "second");
  ck_assert(dll_is_empty(dll));
  dll_destroy(dll);
}
END_TEST

START_TEST(test_dll_push_2_tail_pop_2_tail)
{
  dll_t *dll = NULL;

  ck_assert_ptr_ne(dll = dll_new(), NULL);
  ck_assert(dll_is_empty(dll));
  ck_assert(dll_push_tail(dll, "first"));
  ck_assert(dll_push_tail(dll, "second"));
  ck_assert(!dll_is_empty(dll));
  ck_assert_str_eq(dll_pop_tail(dll), "second");
  ck_assert(!dll_is_empty(dll));
  ck_assert_str_eq(dll_pop_tail(dll), "first");
  ck_assert(dll_is_empty(dll));
  dll_destroy(dll);
}
END_TEST

START_TEST(test_dll_push_2_tail_pop_1_head)
{
  dll_t *dll = NULL;

  ck_assert_ptr_ne(dll = dll_new(), NULL);
  ck_assert(dll_is_empty(dll));
  ck_assert(dll_push_tail(dll, "first"));
  ck_assert(dll_push_tail(dll, "second"));
  ck_assert(!dll_is_empty(dll));
  ck_assert_str_eq(dll_pop_head(dll), "first");
  ck_assert(!dll_is_empty(dll));
  dll_destroy(dll);
}
END_TEST

START_TEST(test_dll_push_2_head_pop_1_tail)
{
  dll_t *dll = NULL;

  ck_assert_ptr_ne(dll = dll_new(), NULL);
  ck_assert(dll_is_empty(dll));
  ck_assert(dll_push_head(dll, "first"));
  ck_assert(dll_push_head(dll, "second"));
  ck_assert(!dll_is_empty(dll));
  ck_assert_str_eq(dll_pop_tail(dll), "first");
  ck_assert(!dll_is_empty(dll));
  dll_destroy(dll);
}
END_TEST

START_TEST(test_dll_push_2_tail_pop_1_tail)
{
  dll_t *dll = NULL;

  ck_assert_ptr_ne(dll = dll_new(), NULL);
  ck_assert(dll_is_empty(dll));
  ck_assert(dll_push_tail(dll, "first"));
  ck_assert(dll_push_tail(dll, "second"));
  ck_assert(!dll_is_empty(dll));
  ck_assert_str_eq(dll_pop_tail(dll), "second");
  ck_assert(!dll_is_empty(dll));
  dll_destroy(dll);
}
END_TEST

START_TEST(test_dll_push_head)
{
  dll_t *dll = NULL;

  ck_assert_ptr_ne(dll = dll_new(), NULL);
  ck_assert(dll_is_empty(dll));
  ck_assert(dll_push_head(dll, "first"));
  ck_assert(!dll_is_empty(dll));
  dll_destroy(dll);
}
END_TEST

START_TEST(test_dll_push_head_pop_head)
{
  dll_t *dll = NULL;

  ck_assert_ptr_ne(dll = dll_new(), NULL);
  ck_assert(dll_is_empty(dll));
  ck_assert(dll_push_head(dll, "first"));
  ck_assert(!dll_is_empty(dll));
  ck_assert_str_eq(dll_pop_head(dll), "first");
  ck_assert(dll_is_empty(dll));
  dll_destroy(dll);
}
END_TEST

START_TEST(test_dll_push_2_head_pop_2_head)
{
  dll_t *dll = NULL;

  ck_assert_ptr_ne(dll = dll_new(), NULL);
  ck_assert(dll_is_empty(dll));
  ck_assert(dll_push_head(dll, "first"));
  ck_assert(!dll_is_empty(dll));
  ck_assert(dll_push_head(dll, "second"));
  ck_assert(!dll_is_empty(dll));
  ck_assert_str_eq(dll_pop_head(dll), "second");
  ck_assert(!dll_is_empty(dll));
  ck_assert_str_eq(dll_pop_head(dll), "first");
  ck_assert(dll_is_empty(dll));
  dll_destroy(dll);
}
END_TEST

START_TEST(test_dll_push_2_head_pop_1_head)
{
  dll_t *dll = NULL;

  ck_assert_ptr_ne(dll = dll_new(), NULL);
  ck_assert(dll_is_empty(dll));
  ck_assert(dll_push_head(dll, "first"));
  ck_assert(!dll_is_empty(dll));
  ck_assert(dll_push_head(dll, "second"));
  ck_assert(!dll_is_empty(dll));
  ck_assert_str_eq(dll_pop_head(dll), "second");
  ck_assert(!dll_is_empty(dll));
  dll_destroy(dll);
}
END_TEST

START_TEST(test_dll_push_1_head_pop_2_head)
{
  dll_t *dll = NULL;

  ck_assert_ptr_ne(dll = dll_new(), NULL);
  ck_assert(dll_is_empty(dll));
  ck_assert(dll_push_head(dll, "first"));
  ck_assert(!dll_is_empty(dll));
  ck_assert_str_eq(dll_pop_head(dll), "first");
  ck_assert(dll_is_empty(dll));
  ck_assert_ptr_eq(dll_pop_head(dll), NULL);
  ck_assert(dll_is_empty(dll));
  dll_destroy(dll);
}
END_TEST

START_TEST(test_dll_push_1_tail_pop_2_head)
{
  dll_t *dll = NULL;

  ck_assert_ptr_ne(dll = dll_new(), NULL);
  ck_assert(dll_is_empty(dll));
  ck_assert(dll_push_tail(dll, "first"));
  ck_assert(!dll_is_empty(dll));
  ck_assert_str_eq(dll_pop_head(dll), "first");
  ck_assert(dll_is_empty(dll));
  ck_assert_ptr_eq(dll_pop_head(dll), NULL);
  ck_assert(dll_is_empty(dll));
  dll_destroy(dll);
}
END_TEST

START_TEST(test_dll_push_1_head_pop_2_tail)
{
  dll_t *dll = NULL;

  ck_assert_ptr_ne(dll = dll_new(), NULL);
  ck_assert(dll_is_empty(dll));
  ck_assert(dll_push_head(dll, "first"));
  ck_assert(!dll_is_empty(dll));
  ck_assert_str_eq(dll_pop_tail(dll), "first");
  ck_assert(dll_is_empty(dll));
  ck_assert_ptr_eq(dll_pop_tail(dll), NULL);
  ck_assert(dll_is_empty(dll));
  dll_destroy(dll);
}
END_TEST

START_TEST(test_dll_push_1_tail_pop_2_tail)
{
  dll_t *dll = NULL;

  ck_assert_ptr_ne(dll = dll_new(), NULL);
  ck_assert(dll_is_empty(dll));
  ck_assert(dll_push_tail(dll, "first"));
  ck_assert(!dll_is_empty(dll));
  ck_assert_str_eq(dll_pop_tail(dll), "first");
  ck_assert(dll_is_empty(dll));
  ck_assert_ptr_eq(dll_pop_tail(dll), NULL);
  ck_assert(dll_is_empty(dll));
  dll_destroy(dll);
}
END_TEST

START_TEST(test_dll_push_head_get_head)
{
  dll_t *dll = NULL;
  dll_node_t *node = NULL;

  ck_assert_ptr_ne(dll = dll_new(), NULL);
  ck_assert(dll_is_empty(dll));
  ck_assert(dll_push_head(dll, "first"));
  ck_assert(!dll_is_empty(dll));
  ck_assert_ptr_ne(node = dll_get_head(dll), NULL);
  ck_assert(!dll_is_empty(dll));
  ck_assert_str_eq(dll_node_get(node), "first");
  dll_destroy(dll);
}
END_TEST

START_TEST(test_dll_push_tail_get_head)
{
  dll_t *dll = NULL;
  dll_node_t *node = NULL;

  ck_assert_ptr_ne(dll = dll_new(), NULL);
  ck_assert(dll_is_empty(dll));
  ck_assert(dll_push_tail(dll, "first"));
  ck_assert(!dll_is_empty(dll));
  ck_assert_ptr_ne(node = dll_get_head(dll), NULL);
  ck_assert(!dll_is_empty(dll));
  ck_assert_str_eq(dll_node_get(node), "first");
  dll_destroy(dll);
}
END_TEST

START_TEST(test_dll_push_2_head_get_all)
{
  dll_t *dll = NULL;
  dll_node_t *node = NULL;

  ck_assert_ptr_ne(dll = dll_new(), NULL);
  ck_assert(dll_is_empty(dll));
  ck_assert(dll_push_head(dll, "first"));
  ck_assert(!dll_is_empty(dll));
  ck_assert_ptr_ne(node = dll_get_head(dll), NULL);
  ck_assert(!dll_is_empty(dll));
  ck_assert_str_eq(dll_node_get(node), "first");
  ck_assert(dll_push_head(dll, "second"));
  ck_assert(!dll_is_empty(dll));
  ck_assert_ptr_ne(node = dll_get_head(dll), NULL);
  ck_assert(!dll_is_empty(dll));
  ck_assert_str_eq(dll_node_get(node), "second");
  ck_assert_ptr_ne(node = dll_node_next(node), NULL);
  ck_assert(!dll_is_empty(dll));
  ck_assert_str_eq(dll_node_get(node), "first");
  ck_assert_ptr_eq(node = dll_node_next(node), NULL);
  dll_destroy(dll);
}
END_TEST

START_TEST(test_dll_push_2_tail_get_all)
{
  dll_t *dll = NULL;
  dll_node_t *node = NULL;

  ck_assert_ptr_ne(dll = dll_new(), NULL);
  ck_assert(dll_is_empty(dll));
  ck_assert(dll_push_tail(dll, "first"));
  ck_assert(!dll_is_empty(dll));
  ck_assert_ptr_ne(node = dll_get_head(dll), NULL);
  ck_assert(!dll_is_empty(dll));
  ck_assert_str_eq(dll_node_get(node), "first");
  ck_assert(dll_push_tail(dll, "second"));
  ck_assert(!dll_is_empty(dll));
  ck_assert_ptr_ne(node = dll_node_next(node), NULL);
  ck_assert(!dll_is_empty(dll));
  ck_assert_str_eq(dll_node_get(node), "second");
  ck_assert_ptr_eq(node = dll_node_next(node), NULL);
  dll_destroy(dll);
}
END_TEST

START_TEST(test_dll_push_head_push_tail_get_all)
{
  dll_t *dll = NULL;
  dll_node_t *node = NULL;

  ck_assert_ptr_ne(dll = dll_new(), NULL);
  ck_assert(dll_is_empty(dll));
  ck_assert(dll_push_head(dll, "first"));
  ck_assert(!dll_is_empty(dll));
  ck_assert_ptr_ne(node = dll_get_head(dll), NULL);
  ck_assert(!dll_is_empty(dll));
  ck_assert_str_eq(dll_node_get(node), "first");
  ck_assert(dll_push_tail(dll, "second"));
  ck_assert(!dll_is_empty(dll));
  ck_assert_ptr_ne(node = dll_node_next(node), NULL);
  ck_assert(!dll_is_empty(dll));
  ck_assert_str_eq(dll_node_get(node), "second");
  ck_assert_ptr_eq(node = dll_node_next(node), NULL);
  dll_destroy(dll);
}
END_TEST

START_TEST(test_dll_push_tail_push_head_get_all)
{
  dll_t *dll = NULL;
  dll_node_t *node = NULL;

  ck_assert_ptr_ne(dll = dll_new(), NULL);
  ck_assert(dll_is_empty(dll));
  ck_assert(dll_push_tail(dll, "first"));
  ck_assert(!dll_is_empty(dll));
  ck_assert_ptr_ne(node = dll_get_head(dll), NULL);
  ck_assert(!dll_is_empty(dll));
  ck_assert_str_eq(dll_node_get(node), "first");
  ck_assert(dll_push_head(dll, "second"));
  ck_assert(!dll_is_empty(dll));
  ck_assert_ptr_ne(node = dll_get_head(dll), NULL);
  ck_assert(!dll_is_empty(dll));
  ck_assert_str_eq(dll_node_get(node), "second");
  ck_assert(!dll_is_empty(dll));
  ck_assert_ptr_ne(node = dll_node_next(node), NULL);
  ck_assert(!dll_is_empty(dll));
  ck_assert_str_eq(dll_node_get(node), "first");
  ck_assert_ptr_eq(node = dll_node_next(node), NULL);
  dll_destroy(dll);
}
END_TEST

START_TEST(test_dll_get_head_from_empty)
{
  dll_t *dll = NULL;

  ck_assert_ptr_ne(dll = dll_new(), NULL);
  ck_assert(dll_is_empty(dll));
  ck_assert_ptr_eq(dll_get_head(dll), NULL);
  dll_destroy(dll);
}
END_TEST

START_TEST(test_dll_iterate_from_null)
{
  ck_assert_ptr_eq(dll_node_next(NULL), NULL);
}
END_TEST

START_TEST(test_dll_push_7_tail_and_iterate)
{
  dll_t *dll = NULL;
  dll_node_t *node = NULL;

  ck_assert_ptr_ne(dll = dll_new(), NULL);
  ck_assert(dll_is_empty(dll));
  ck_assert(dll_push_tail(dll, "first"));
  ck_assert(!dll_is_empty(dll));
  ck_assert(dll_push_tail(dll, "second"));
  ck_assert(!dll_is_empty(dll));
  ck_assert(dll_push_tail(dll, "third"));
  ck_assert(!dll_is_empty(dll));
  ck_assert(dll_push_tail(dll, "fourth"));
  ck_assert(!dll_is_empty(dll));
  ck_assert(dll_push_tail(dll, "fifth"));
  ck_assert(!dll_is_empty(dll));
  ck_assert(dll_push_tail(dll, "sixth"));
  ck_assert(!dll_is_empty(dll));
  ck_assert(dll_push_tail(dll, "seventh"));
  ck_assert(!dll_is_empty(dll));
  ck_assert_ptr_ne(node = dll_get_head(dll), NULL);
  ck_assert_str_eq(dll_node_get(node), "first");
  ck_assert_ptr_ne(node = dll_node_next(node), NULL);
  ck_assert_str_eq(dll_node_get(node), "second");
  ck_assert_ptr_ne(node = dll_node_next(node), NULL);
  ck_assert_str_eq(dll_node_get(node), "third");
  ck_assert_ptr_ne(node = dll_node_next(node), NULL);
  ck_assert_str_eq(dll_node_get(node), "fourth");
  ck_assert_ptr_ne(node = dll_node_next(node), NULL);
  ck_assert_str_eq(dll_node_get(node), "fifth");
  ck_assert_ptr_ne(node = dll_node_next(node), NULL);
  ck_assert_str_eq(dll_node_get(node), "sixth");
  ck_assert_ptr_ne(node = dll_node_next(node), NULL);
  ck_assert_str_eq(dll_node_get(node), "seventh");
  dll_destroy(dll);
}
END_TEST

START_TEST(test_dll_push_7_head_and_iterate)
{
  dll_t *dll = NULL;
  dll_node_t *node = NULL;

  ck_assert_ptr_ne(dll = dll_new(), NULL);
  ck_assert(dll_is_empty(dll));
  ck_assert(dll_push_head(dll, "first"));
  ck_assert(!dll_is_empty(dll));
  ck_assert(dll_push_head(dll, "second"));
  ck_assert(!dll_is_empty(dll));
  ck_assert(dll_push_head(dll, "third"));
  ck_assert(!dll_is_empty(dll));
  ck_assert(dll_push_head(dll, "fourth"));
  ck_assert(!dll_is_empty(dll));
  ck_assert(dll_push_head(dll, "fifth"));
  ck_assert(!dll_is_empty(dll));
  ck_assert(dll_push_head(dll, "sixth"));
  ck_assert(!dll_is_empty(dll));
  ck_assert(dll_push_head(dll, "seventh"));
  ck_assert(!dll_is_empty(dll));
  ck_assert_ptr_ne(node = dll_get_head(dll), NULL);
  ck_assert_str_eq(dll_node_get(node), "seventh");
  ck_assert_ptr_ne(node = dll_node_next(node), NULL);
  ck_assert_str_eq(dll_node_get(node), "sixth");
  ck_assert_ptr_ne(node = dll_node_next(node), NULL);
  ck_assert_str_eq(dll_node_get(node), "fifth");
  ck_assert_ptr_ne(node = dll_node_next(node), NULL);
  ck_assert_str_eq(dll_node_get(node), "fourth");
  ck_assert_ptr_ne(node = dll_node_next(node), NULL);
  ck_assert_str_eq(dll_node_get(node), "third");
  ck_assert_ptr_ne(node = dll_node_next(node), NULL);
  ck_assert_str_eq(dll_node_get(node), "second");
  ck_assert_ptr_ne(node = dll_node_next(node), NULL);
  ck_assert_str_eq(dll_node_get(node), "first");
  dll_destroy(dll);
}
END_TEST

START_TEST(test_dll_push_7_head_and_iterate_in_for_each_loop)
{
  dll_t *dll = NULL;
  dll_node_t *node = NULL;

  ck_assert_ptr_ne(dll = dll_new(), NULL);
  ck_assert(dll_is_empty(dll));
  ck_assert(dll_push_head(dll, "first"));
  ck_assert(!dll_is_empty(dll));
  ck_assert(dll_push_head(dll, "second"));
  ck_assert(!dll_is_empty(dll));
  ck_assert(dll_push_head(dll, "third"));
  ck_assert(!dll_is_empty(dll));
  ck_assert(dll_push_head(dll, "fourth"));
  ck_assert(!dll_is_empty(dll));
  ck_assert(dll_push_head(dll, "fifth"));
  ck_assert(!dll_is_empty(dll));
  ck_assert(dll_push_head(dll, "sixth"));
  ck_assert(!dll_is_empty(dll));
  ck_assert(dll_push_head(dll, "seventh"));
  ck_assert(!dll_is_empty(dll));

  DLL_FOR_EACH_BEGIN(dll, node)
  {
    ck_assert(dll_node_get(node));
  }
  DLL_FOR_EACH_END
  dll_destroy(dll);
}
END_TEST

Suite *
dll_suite(void)
{
  Suite *s = NULL;
  TCase *tc_core = NULL;
  TCase *tc_nodes = NULL;
  TCase *tc_foreach = NULL;

  s = suite_create("Doubly linked list");

  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, test_dll_new);
  tcase_add_test(tc_core, test_dll_push_head);
  tcase_add_test(tc_core, test_dll_push_tail);
  tcase_add_test(tc_core, test_dll_pop_head_empty);
  tcase_add_test(tc_core, test_dll_pop_tail_empty);
  tcase_add_test(tc_core, test_dll_push_head_pop_head);
  tcase_add_test(tc_core, test_dll_push_tail_pop_head);
  tcase_add_test(tc_core, test_dll_push_head_pop_tail);
  tcase_add_test(tc_core, test_dll_push_tail_pop_tail);
  tcase_add_test(tc_core, test_dll_push_2_head_pop_2_head);
  tcase_add_test(tc_core, test_dll_push_2_tail_pop_2_head);
  tcase_add_test(tc_core, test_dll_push_2_head_pop_2_tail);
  tcase_add_test(tc_core, test_dll_push_2_tail_pop_2_tail);
  tcase_add_test(tc_core, test_dll_push_2_head_pop_1_head);
  tcase_add_test(tc_core, test_dll_push_2_tail_pop_1_head);
  tcase_add_test(tc_core, test_dll_push_2_head_pop_1_tail);
  tcase_add_test(tc_core, test_dll_push_2_tail_pop_1_tail);
  tcase_add_test(tc_core, test_dll_push_1_head_pop_2_head);
  tcase_add_test(tc_core, test_dll_push_1_tail_pop_2_head);
  tcase_add_test(tc_core, test_dll_push_1_head_pop_2_tail);
  tcase_add_test(tc_core, test_dll_push_1_tail_pop_2_tail);
  suite_add_tcase(s, tc_core);

  tc_nodes = tcase_create("Nodes");
  tcase_add_test(tc_nodes, test_dll_get_head_from_empty);
  tcase_add_test(tc_nodes, test_dll_iterate_from_null);
  tcase_add_test(tc_nodes, test_dll_push_head_get_head);
  tcase_add_test(tc_nodes, test_dll_push_tail_get_head);
  tcase_add_test(tc_nodes, test_dll_push_2_head_get_all);
  tcase_add_test(tc_nodes, test_dll_push_2_tail_get_all);
  tcase_add_test(tc_nodes, test_dll_push_head_push_tail_get_all);
  tcase_add_test(tc_nodes, test_dll_push_tail_push_head_get_all);
  tcase_add_test(tc_nodes, test_dll_push_7_tail_and_iterate);
  tcase_add_test(tc_nodes, test_dll_push_7_head_and_iterate);
  suite_add_tcase(s, tc_nodes);

  tc_foreach = tcase_create("For each");
  tcase_add_test(tc_foreach, test_dll_push_7_head_and_iterate_in_for_each_loop);
  suite_add_tcase(s, tc_foreach);

  return s;
}
