#include "defines.h"
#include "emp.h"
#include "gldll.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int
main(void)
{
  int retval = EXIT_FAILURE;
  emp_t *emp = NULL;

  /* Creating one employee object */
  TRY_DONE(emp = emp_new(), "Employee creation failed");
  emp_set_name(emp, "Neha");
  emp_set_salary(emp, 50000);
  emp_set_designation(emp, "HR");
  emp_set_id(emp, 21);

  /* Invoking fn to print employee details, implemented in emp.c */
  emp_print_contents(&emp->glnode);

  retval = EXIT_SUCCESS;

done:
  emp_destroy(emp);

  return retval;
}
