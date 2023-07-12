#include "serialize_suite.h"
#include <check.h>
#include <stdlib.h>

int
main(void)
{
  int number_failed;
  SRunner *sr = NULL;

  sr = srunner_create(serialize_suite());

  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
