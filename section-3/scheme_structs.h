#ifndef SCHEME_STRUCTS
#define SCHEME_STRUCTS

#include "scheme_utils.h"
#include "symbol_struct.h"

enum { ATOM, LIST, SYMBOL };

typedef struct scheme_value
{
  int type;
  union
  {
    ptr atom;
    symbol symbol;
    struct scheme_cell *list;
  }value;

}scheme_value;

typedef struct scheme_cell
{
  scheme_value *car;
  scheme_value *cdr;
}scheme_cell;

scheme_cell *cons(scheme_cell *cell1, scheme_cell *cell2);

scheme_value *car(scheme_value *list);

scheme_value *cdr(scheme_value *list);

#endif
