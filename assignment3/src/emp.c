#include "emp.h"
#include "defines.h"
#include "gldll.h"
#include "container.h"
#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool
emp_init(emp_t *self)
{
  assert(self);

  CLEAR(self, emp_t);

  return gldll_node_init(&self->glnode);
}

void
emp_finalize(emp_t *self)
{
  assert(self);

  gldll_node_finalize(&self->glnode);
}

emp_t *
emp_new(void)
{
  emp_t *new_object = NULL;

  ALLOCATE_FAIL(new_object, emp_t);
  TRY_FAIL(emp_init(new_object), "Employee initialization failed");

  return new_object;

fail:
  if (new_object)
    free(new_object);

  return NULL;
}

void
emp_destroy(emp_t *self)
{
  if (self) {
    emp_finalize(self);
    free(self);
  }
}

void
emp_set_name(emp_t *self, const char *name)
{
  assert(self);
  assert(name);

  strncpy(self->name, name, EMP_STR_MAXSIZE);
}

void
emp_set_salary(emp_t *self, unsigned int salary)
{
  assert(self);

  self->salary = salary;
}

void
emp_set_designation(emp_t *self, const char *designation)
{
  assert(self);
  assert(designation);

  strncpy(self->designation, designation, EMP_STR_MAXSIZE);
}

void
emp_set_id(emp_t *self, unsigned int id)
{
  assert(self);

  self->emp_id = id;
}

const char *
emp_get_name(const emp_t *self)
{
  assert(self);

  return self->name;
}

unsigned int
emp_get_salary(const emp_t *self)
{
  assert(self);

  return self->salary;
}

const char *
emp_get_designation(const emp_t *self)
{
  assert(self);

  return self->designation;
}

unsigned int
emp_get_id(const emp_t *self)
{
  assert(self);

  return self->emp_id;
}

void
emp_print(emp_t *self)
{
  assert(self);

  printf("Employee name = %s\n", self->name);
  printf("salary = %u\n", self->salary);
  printf("designation = %s\n", self->designation);
  printf("emp_id = %u\n", self->emp_id);
}

convert_to_container_func(emp_t, glnode, gldll_node_t)

/*Implement the below function*/
void
emp_print_contents(gldll_node_t *node)
{
  assert(node);

  emp_print(gldll_node_t_to_emp_t(node));
}
