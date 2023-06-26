#include "bt_suite.h"
#include "bt.h"
#include <check.h>
#include <stdio.h>
#include <stdlib.h>

START_TEST(test_bt_new)
{
  bt_t *bt = NULL;

  ck_assert_ptr_ne(bt = bt_new(), NULL);
  ck_assert(bt_is_empty(bt));
  ck_assert_ptr_eq(bt_get_first_node_inorder(bt), NULL);
  bt_destroy(bt);
}
END_TEST

START_TEST(test_bt_delete_from_empty)
{
  bt_t *bt = NULL;

  ck_assert_ptr_ne(bt = bt_new(), NULL);
  ck_assert(bt_is_empty(bt));
  ck_assert_ptr_eq(bt_get_first_node_inorder(bt), NULL);
  ck_assert(!bt_delete(bt, "first"));
  ck_assert(bt_is_empty(bt));
  ck_assert_ptr_eq(bt_get_first_node_inorder(bt), NULL);
  bt_destroy(bt);
}
END_TEST

START_TEST(test_bt_insert_and_delete)
{
  bt_t *bt = NULL;
  bt_node_t *node = NULL;

  ck_assert_ptr_ne(bt = bt_new(), NULL);
  ck_assert(bt_is_empty(bt));
  ck_assert_ptr_eq(bt_get_first_node_inorder(bt), NULL);
  ck_assert(bt_insert(bt, "first"));
  ck_assert(!bt_is_empty(bt));
  ck_assert_ptr_ne(node = bt_get_first_node_inorder(bt), NULL);
  ck_assert_str_eq(bt_node_get(node), "first");
  ck_assert_ptr_eq(bt_node_next_inorder(node), NULL);
  ck_assert(bt_delete(bt, "first"));
  ck_assert(bt_is_empty(bt));
  ck_assert_ptr_eq(node = bt_get_first_node_inorder(bt), NULL);
  bt_destroy(bt);
}
END_TEST

START_TEST(test_bt_insert_2_and_delete_1)
{
  bt_t *bt = NULL;
  bt_node_t *node = NULL;

  ck_assert_ptr_ne(bt = bt_new(), NULL);
  ck_assert(bt_is_empty(bt));
  ck_assert_ptr_eq(bt_get_first_node_inorder(bt), NULL);
  ck_assert(bt_insert(bt, "first"));
  ck_assert(!bt_is_empty(bt));
  ck_assert_ptr_ne(node = bt_get_first_node_inorder(bt), NULL);
  ck_assert_str_eq(bt_node_get(node), "first");
  ck_assert_ptr_eq(bt_node_next_inorder(node), NULL);
  ck_assert(bt_insert(bt, "second"));
  ck_assert(!bt_is_empty(bt));
  ck_assert_ptr_ne(node = bt_get_first_node_inorder(bt), NULL);
  ck_assert_str_eq(bt_node_get(node), "second");
  ck_assert_ptr_ne(node = bt_node_next_inorder(node), NULL);
  ck_assert_str_eq(bt_node_get(node), "first");
  ck_assert_ptr_eq(bt_node_next_inorder(node), NULL);
  ck_assert(bt_delete(bt, "first"));
  ck_assert(!bt_is_empty(bt));
  ck_assert_ptr_ne(node = bt_get_first_node_inorder(bt), NULL);
  ck_assert_str_eq(bt_node_get(node), "second");
  ck_assert_ptr_eq(bt_node_next_inorder(node), NULL);
  bt_destroy(bt);
}
END_TEST

START_TEST(test_bt_insert_2_and_delete_2)
{
  bt_t *bt = NULL;
  bt_node_t *node = NULL;

  ck_assert_ptr_ne(bt = bt_new(), NULL);
  ck_assert(bt_is_empty(bt));
  ck_assert_ptr_eq(bt_get_first_node_inorder(bt), NULL);
  ck_assert(bt_insert(bt, "first"));
  ck_assert(!bt_is_empty(bt));
  ck_assert_ptr_ne(node = bt_get_first_node_inorder(bt), NULL);
  ck_assert_str_eq(bt_node_get(node), "first");
  ck_assert_ptr_eq(bt_node_next_inorder(node), NULL);
  ck_assert(bt_insert(bt, "second"));
  ck_assert(!bt_is_empty(bt));
  ck_assert_ptr_ne(node = bt_get_first_node_inorder(bt), NULL);
  ck_assert_str_eq(bt_node_get(node), "second");
  ck_assert_ptr_ne(node = bt_node_next_inorder(node), NULL);
  ck_assert_str_eq(bt_node_get(node), "first");
  ck_assert_ptr_eq(bt_node_next_inorder(node), NULL);
  ck_assert(bt_delete(bt, "first"));
  ck_assert(!bt_is_empty(bt));
  ck_assert_ptr_ne(node = bt_get_first_node_inorder(bt), NULL);
  ck_assert_str_eq(bt_node_get(node), "second");
  ck_assert_ptr_eq(bt_node_next_inorder(node), NULL);
  ck_assert(bt_delete(bt, "second"));
  ck_assert(bt_is_empty(bt));
  ck_assert_ptr_eq(bt_get_first_node_inorder(bt), NULL);
  bt_destroy(bt);
}
END_TEST

START_TEST(test_bt_insert_3_and_delete_3)
{
  bt_t *bt = NULL;
  bt_node_t *node = NULL;

  ck_assert_ptr_ne(bt = bt_new(), NULL);
  ck_assert(bt_is_empty(bt));
  ck_assert_ptr_eq(bt_get_first_node_inorder(bt), NULL);
  ck_assert(bt_insert(bt, "first"));
  ck_assert(!bt_is_empty(bt));
  ck_assert_ptr_ne(node = bt_get_first_node_inorder(bt), NULL);
  ck_assert_str_eq(bt_node_get(node), "first");
  ck_assert_ptr_eq(bt_node_next_inorder(node), NULL);
  ck_assert(bt_insert(bt, "second"));
  ck_assert(!bt_is_empty(bt));
  ck_assert_ptr_ne(node = bt_get_first_node_inorder(bt), NULL);
  ck_assert_str_eq(bt_node_get(node), "second");
  ck_assert_ptr_ne(node = bt_node_next_inorder(node), NULL);
  ck_assert_str_eq(bt_node_get(node), "first");
  ck_assert_ptr_eq(bt_node_next_inorder(node), NULL);
  ck_assert(bt_insert(bt, "third"));
  ck_assert(!bt_is_empty(bt));
  ck_assert_ptr_ne(node = bt_get_first_node_inorder(bt), NULL);
  ck_assert_str_eq(bt_node_get(node), "second");
  ck_assert_ptr_ne(node = bt_node_next_inorder(node), NULL);
  ck_assert_str_eq(bt_node_get(node), "first");
  ck_assert_ptr_ne(node = bt_node_next_inorder(node), NULL);
  ck_assert_str_eq(bt_node_get(node), "third");
  ck_assert_ptr_eq(bt_node_next_inorder(node), NULL);
  ck_assert(bt_delete(bt, "first"));
  ck_assert(!bt_is_empty(bt));
  ck_assert_ptr_ne(node = bt_get_first_node_inorder(bt), NULL);
  ck_assert_str_eq(bt_node_get(node), "second");
  ck_assert_ptr_ne(node = bt_node_next_inorder(node), NULL);
  ck_assert_str_eq(bt_node_get(node), "third");
  ck_assert_ptr_eq(bt_node_next_inorder(node), NULL);
  ck_assert(bt_delete(bt, "second"));
  ck_assert(!bt_is_empty(bt));
  ck_assert_ptr_ne(node = bt_get_first_node_inorder(bt), NULL);
  ck_assert_str_eq(bt_node_get(node), "third");
  ck_assert_ptr_eq(bt_node_next_inorder(node), NULL);
  ck_assert(bt_delete(bt, "third"));
  ck_assert_ptr_eq(bt_get_first_node_inorder(bt), NULL);
  ck_assert(bt_is_empty(bt));
  bt_destroy(bt);
}
END_TEST

START_TEST(test_bt_insert_4_and_delete_4)
{
  bt_t *bt = NULL;
  bt_node_t *node = NULL;

  ck_assert_ptr_ne(bt = bt_new(), NULL);
  ck_assert(bt_is_empty(bt));
  ck_assert_ptr_eq(bt_get_first_node_inorder(bt), NULL);
  ck_assert(bt_insert(bt, "first"));
  ck_assert(!bt_is_empty(bt));
  ck_assert_ptr_ne(node = bt_get_first_node_inorder(bt), NULL);
  ck_assert_str_eq(bt_node_get(node), "first");
  ck_assert_ptr_eq(bt_node_next_inorder(node), NULL);
  ck_assert(bt_insert(bt, "second"));
  ck_assert(!bt_is_empty(bt));
  ck_assert_ptr_ne(node = bt_get_first_node_inorder(bt), NULL);
  ck_assert_str_eq(bt_node_get(node), "second");
  ck_assert_ptr_ne(node = bt_node_next_inorder(node), NULL);
  ck_assert_str_eq(bt_node_get(node), "first");
  ck_assert_ptr_eq(bt_node_next_inorder(node), NULL);
  ck_assert(bt_insert(bt, "third"));
  ck_assert(!bt_is_empty(bt));
  ck_assert_ptr_ne(node = bt_get_first_node_inorder(bt), NULL);
  ck_assert_str_eq(bt_node_get(node), "second");
  ck_assert_ptr_ne(node = bt_node_next_inorder(node), NULL);
  ck_assert_str_eq(bt_node_get(node), "first");
  ck_assert_ptr_ne(node = bt_node_next_inorder(node), NULL);
  ck_assert_str_eq(bt_node_get(node), "third");
  ck_assert_ptr_eq(bt_node_next_inorder(node), NULL);
  ck_assert(bt_insert(bt, "fourth"));
  ck_assert(!bt_is_empty(bt));
  ck_assert_ptr_ne(node = bt_get_first_node_inorder(bt), NULL);
  ck_assert_str_eq(bt_node_get(node), "fourth");
  ck_assert_ptr_ne(node = bt_node_next_inorder(node), NULL);
  ck_assert_str_eq(bt_node_get(node), "second");
  ck_assert_ptr_ne(node = bt_node_next_inorder(node), NULL);
  ck_assert_str_eq(bt_node_get(node), "first");
  ck_assert_ptr_ne(node = bt_node_next_inorder(node), NULL);
  ck_assert_str_eq(bt_node_get(node), "third");
  ck_assert_ptr_eq(bt_node_next_inorder(node), NULL);
  ck_assert(bt_delete(bt, "second"));
  ck_assert(!bt_is_empty(bt));
  ck_assert_ptr_ne(node = bt_get_first_node_inorder(bt), NULL);
  ck_assert_str_eq(bt_node_get(node), "fourth");
  ck_assert_ptr_ne(node = bt_node_next_inorder(node), NULL);
  ck_assert_str_eq(bt_node_get(node), "first");
  ck_assert_ptr_ne(node = bt_node_next_inorder(node), NULL);
  ck_assert_str_eq(bt_node_get(node), "third");
  ck_assert_ptr_eq(bt_node_next_inorder(node), NULL);
  ck_assert(bt_delete(bt, "fourth"));
  ck_assert(!bt_is_empty(bt));
  ck_assert_ptr_ne(node = bt_get_first_node_inorder(bt), NULL);
  ck_assert_str_eq(bt_node_get(node), "third");
  ck_assert_ptr_ne(node = bt_node_next_inorder(node), NULL);
  ck_assert_str_eq(bt_node_get(node), "first");
  ck_assert_ptr_eq(bt_node_next_inorder(node), NULL);
  ck_assert(bt_delete(bt, "first"));
  ck_assert(!bt_is_empty(bt));
  ck_assert_ptr_ne(node = bt_get_first_node_inorder(bt), NULL);
  ck_assert_str_eq(bt_node_get(node), "third");
  ck_assert_ptr_eq(bt_node_next_inorder(node), NULL);
  ck_assert(bt_delete(bt, "third"));
  ck_assert(bt_is_empty(bt));
  ck_assert_ptr_eq(bt_get_first_node_inorder(bt), NULL);
  bt_destroy(bt);
}
END_TEST

START_TEST(test_bt_iterate_from_null)
{
  ck_assert_ptr_eq(bt_node_next_inorder(NULL), NULL);
}
END_TEST

START_TEST(test_bt_insert_7_iterate_inorder)
{
  bt_t *bt = NULL;
  bt_node_t *node = NULL;

  ck_assert_ptr_ne(bt = bt_new(), NULL);
  ck_assert(bt_is_empty(bt));
  ck_assert(bt_insert(bt, "first"));
  ck_assert(!bt_is_empty(bt));
  ck_assert(bt_insert(bt, "second"));
  ck_assert(!bt_is_empty(bt));
  ck_assert(bt_insert(bt, "third"));
  ck_assert(!bt_is_empty(bt));
  ck_assert(bt_insert(bt, "fourth"));
  ck_assert(!bt_is_empty(bt));
  ck_assert(bt_insert(bt, "fifth"));
  ck_assert(!bt_is_empty(bt));
  ck_assert(bt_insert(bt, "sixth"));
  ck_assert(!bt_is_empty(bt));
  ck_assert(bt_insert(bt, "seventh"));
  ck_assert(!bt_is_empty(bt));
  ck_assert_ptr_ne(node = bt_get_first_node_inorder(bt), NULL);
  ck_assert_str_eq(bt_node_get(node), "fourth");
  ck_assert_ptr_ne(node = bt_node_next_inorder(node), NULL);
  ck_assert_str_eq(bt_node_get(node), "second");
  ck_assert_ptr_ne(node = bt_node_next_inorder(node), NULL);
  ck_assert_str_eq(bt_node_get(node), "fifth");
  ck_assert_ptr_ne(node = bt_node_next_inorder(node), NULL);
  ck_assert_str_eq(bt_node_get(node), "first");
  ck_assert_ptr_ne(node = bt_node_next_inorder(node), NULL);
  ck_assert_str_eq(bt_node_get(node), "sixth");
  ck_assert_ptr_ne(node = bt_node_next_inorder(node), NULL);
  ck_assert_str_eq(bt_node_get(node), "third");
  ck_assert_ptr_ne(node = bt_node_next_inorder(node), NULL);
  ck_assert_str_eq(bt_node_get(node), "seventh");
  ck_assert_ptr_eq(node = bt_node_next_inorder(node), NULL);
  ck_assert(bt_delete(bt, "second"));
  ck_assert(!bt_is_empty(bt));
  ck_assert(bt_delete(bt, "fourth"));
  ck_assert(!bt_is_empty(bt));
  ck_assert(bt_delete(bt, "first"));
  ck_assert(!bt_is_empty(bt));
  ck_assert(bt_delete(bt, "third"));
  ck_assert(!bt_is_empty(bt));
  ck_assert(bt_delete(bt, "fifth"));
  ck_assert(!bt_is_empty(bt));
  ck_assert(bt_delete(bt, "sixth"));
  ck_assert(!bt_is_empty(bt));
  ck_assert(bt_delete(bt, "seventh"));
  ck_assert(bt_is_empty(bt));
  bt_destroy(bt);
}
END_TEST

START_TEST(test_bt_push_7_head_and_iterate_in_for_each_loop)
{
  bt_t *bt = NULL;
  bt_node_t *node = NULL;

  ck_assert(bt = bt_new());
  ck_assert(bt_is_empty(bt));
  ck_assert(bt_insert(bt, "first"));
  ck_assert(!bt_is_empty(bt));
  ck_assert(bt_insert(bt, "second"));
  ck_assert(!bt_is_empty(bt));
  ck_assert(bt_insert(bt, "third"));
  ck_assert(!bt_is_empty(bt));
  ck_assert(bt_insert(bt, "fourth"));
  ck_assert(!bt_is_empty(bt));
  ck_assert(bt_insert(bt, "fifth"));
  ck_assert(!bt_is_empty(bt));
  ck_assert(bt_insert(bt, "sixth"));
  ck_assert(!bt_is_empty(bt));
  ck_assert(bt_insert(bt, "seventh"));
  ck_assert(!bt_is_empty(bt));

  BT_FOR_EACH_BEGIN(bt, node)
  {
    ck_assert(bt_node_get(node));
  }
  BT_FOR_EACH_END bt_destroy(bt);
}
END_TEST

Suite *
bt_suite(void)
{
  Suite *s = NULL;
  TCase *tc_core = NULL;
  TCase *tc_node = NULL;
  TCase *tc_foreach = NULL;

  s = suite_create("Binary tree");

  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, test_bt_new);
  tcase_add_test(tc_core, test_bt_delete_from_empty);
  tcase_add_test(tc_core, test_bt_insert_and_delete);
  tcase_add_test(tc_core, test_bt_insert_2_and_delete_1);
  tcase_add_test(tc_core, test_bt_insert_2_and_delete_2);
  tcase_add_test(tc_core, test_bt_insert_3_and_delete_3);
  tcase_add_test(tc_core, test_bt_insert_4_and_delete_4);
  suite_add_tcase(s, tc_core);

  tc_node = tcase_create("Node");
  tcase_add_test(tc_node, test_bt_iterate_from_null);
  tcase_add_test(tc_node, test_bt_insert_7_iterate_inorder);
  suite_add_tcase(s, tc_node);

  tc_foreach = tcase_create("For each");
  tcase_add_test(tc_foreach, test_bt_push_7_head_and_iterate_in_for_each_loop);
  suite_add_tcase(s, tc_foreach);

  return s;
}
