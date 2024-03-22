#include <stdio.h>

#include <check.h>
#include "linkedlist.h"

START_TEST (test_empty_linkedlist)
{
	LinkedList *ll = linkedlist();
	ck_assert(ll->head == NULL);
	free_linked_list(&ll);
}
END_TEST

START_TEST (test_add_int)
{
	LinkedList *ll = linkedlist();
	int num1 = 1232;
	add(ll, INT, &num1);
	ck_assert(ll->head->data.int_value == 1232);
	free_linked_list(&ll);
}
END_TEST

START_TEST (test_add_float)
{
	LinkedList *ll = linkedlist();
	float float1 = 1232.16;
	add(ll, FLOAT, &float1);
	ck_assert(fabs(ll->head->data.float_value - 1232.16) < 0.0001 );
	free_linked_list(&ll);
}
END_TEST

START_TEST (test_add_char)
{
	LinkedList *ll = linkedlist();
	char char1 = 'a';
	add(ll, CHAR, &char1);
	ck_assert(ll->head->data.char_value == 'a');
	free_linked_list(&ll);
}
END_TEST

START_TEST (test_add_string)
{
	LinkedList *ll = linkedlist();
	char *string1 = "Hello World!";
	add(ll, STRING, string1);
	ck_assert(ll->head->data.string_value == string1);
	free_linked_list(&ll);
}
END_TEST

START_TEST (test_print_linkedlist)
{
	LinkedList *ll = linkedlist();
	int num1 = 1232;
	float float1 = 1232.16;
	char char1 = 'a';
	char *string1 = "Hello World!";
	add(ll, INT, &num1);
	add(ll, FLOAT, &float1);
	add(ll, CHAR, &char1);
	add(ll, STRING, string1);

	print_linkedlist(ll);

	free_linked_list(&ll);
	ck_assert(ll == NULL);
}
END_TEST

START_TEST (test_free_linkedlist)
{
	LinkedList *ll = linkedlist();
	ck_assert(ll != NULL);

	// add nodes and test

	free_linked_list(&ll);
	ck_assert(ll == NULL);
}
END_TEST

/**********************************************
 * Machinery for running the 'check' tests.  */
Suite *linkedlist_suite(void)
{
  Suite *suite = suite_create("linkedlist\n");
  TCase *tc_core = tcase_create("Core");
  
  suite_add_tcase(suite, tc_core);

  tcase_add_test(tc_core, test_empty_linkedlist);
  tcase_add_test(tc_core, test_free_linkedlist);
  tcase_add_test(tc_core, test_add_int);
  tcase_add_test(tc_core, test_add_float);
  tcase_add_test(tc_core, test_add_char);
  tcase_add_test(tc_core, test_add_string);
  tcase_add_test(tc_core, test_print_linkedlist);
  return suite;
}

/**********************************************/
int main(void) {
	int failure_count;
	Suite *suite = linkedlist_suite();
	SRunner *suite_runner = srunner_create(suite);

	srunner_run_all(suite_runner, CK_VERBOSE);

	failure_count = srunner_ntests_failed(suite_runner);

	srunner_free(suite_runner);

	return ( failure_count == 0 ) ? 0 : 1;
}


// test the freeing part
