#include "scheme_structs.h"

scheme_cell *cons(scheme_cell *cell1, scheme_cell *cell2)
{
  scheme_cell *new_cell = malloc(sizeof(scheme_cell));
  new_cell->car = cell1->car;
  new_cell->cdr = cell2->car;
  return new_cell;
}

scheme_value *car(scheme_value *list)
{
  return list->value.list->car;
}

scheme_value *cdr(scheme_value *list)
{
  return list->value.list->cdr;
}
