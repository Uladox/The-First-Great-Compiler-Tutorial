#include "scheme_structs.h"
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

scheme_cell *SymbolList;

scheme_value *add_new_symbol(char *symbol_name)
{
  scheme_cell *new_symbol = malloc(sizeof(scheme_cell));
  scheme_value *symbol_value = malloc(sizeof(scheme_value));
  symbol_value->type = SYMBOL;
  symbol_value->value.symbol.symbol_name = malloc(strlen(symbol_name) + 1);
  strcpy(symbol_value->value.symbol.symbol_name, symbol_name);
  new_symbol->car = symbol_value;
  
  SymbolList = cons(new_symbol, SymbolList);
  return symbol_value;
}

scheme_value *add_new_symbol_first(char *symbol_name)
{
  scheme_cell *new_symbol = malloc(sizeof(scheme_cell));
  scheme_value *symbol_value = malloc(sizeof(scheme_value));
  symbol_value->type = SYMBOL;
  symbol_value->value.symbol.symbol_name = malloc(strlen(symbol_name) + 1);
  strcpy(symbol_value->value.symbol.symbol_name, symbol_name);
  new_symbol->car = symbol_value;
  
  SymbolList = new_symbol;
  return symbol_value;
}

void init_symbols()
{
  add_new_symbol_first("nil");
}

scheme_value *get_symbol(char *symbol_name)
{
  scheme_cell *current_cell = SymbolList;
  while(1) {
    if(current_cell->car->type == ATOM)
      if(current_cell->car->value.atom == nil)
	return add_new_symbol(symbol_name);
      else {
	fprintf(stderr, "Non nil atom in symbol list");
	exit (EXIT_FAILURE);
      }
    
    if(strcmp(symbol_name, current_cell->car->value.symbol.symbol_name) == 0)
      return current_cell->car;
    current_cell = current_cell->cdr->value.list;
  }
}
