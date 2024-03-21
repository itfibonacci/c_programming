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

START_TEST (test_add)
{
	LinkedList *ll = linkedlist();
	

	free_linked_list(&ll);
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
  tcase_add_test(tc_core, test_add);

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
