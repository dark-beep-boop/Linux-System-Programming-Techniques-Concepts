#include "student.h"
#include "defines.h"
#include <assert.h>
#include <stdlib.h>
#include <string.h>

bool
student_init(student_t *self)
{
  assert(self);

  CLEAR(self, student_t);

  return true;
}

void
student_finalize(student_t *self)
{
  assert(self);
}

student_t *
student_new(void)
{
  student_t *new_object = NULL;

  ALLOCATE_FAIL(new_object, student_t);
  TRY_FAIL(student_init(new_object), "student initialization failed");

  return new_object;

fail:
  if (new_object)
    free(new_object);

  return NULL;
}

void
student_destroy(student_t *self)
{
  if (self) {
    student_finalize(self);
    free(self);
  }
}

bool
student_set_name(student_t *self, const char *name)
{
  assert(self);
  assert(name);

  strncpy(self->name, name, NAME_MAX_LEN);

  return true;
}

bool
student_set_year_of_birth(student_t *self, unsigned int year_of_birth)
{
  assert(self);

  self->year_of_birth = year_of_birth;

  return true;
}

bool
student_set_height(student_t *self, unsigned int height)
{
  assert(self);

  self->height = height;

  return true;
}

bool
student_set_weight(student_t *self, unsigned int weight)
{
  assert(self);

  self->weight = weight;

  return true;
}

bool
student_set_total_marks(student_t *self, unsigned int total_marks)
{
  assert(self);

  self->total_marks = total_marks;

  return true;
}

const char *
student_get_name(student_t *self)
{
  assert(self);

  return self->name;
}

unsigned int
student_get_year_of_birth(student_t *self)
{
  assert(self);

  return self->year_of_birth;
}

unsigned int
student_get_height(student_t *self)
{
  assert(self);

  return self->height;
}

unsigned int
student_get_weight(student_t *self)
{
  assert(self);

  return self->weight;
}

unsigned int
student_get_total_marks(student_t *self)
{
  assert(self);

  return self->total_marks;
}

/* Step 3: implement student comparator function here */
int
student_compare(student_t *self, student_t *other)
{
  assert(self);
  assert(other);

  return memcmp(self, other, sizeof(student_t)) == 0 ? 0 : -1;
}
