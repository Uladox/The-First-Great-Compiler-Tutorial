#ifndef SYMBOLS
#define SYMBOLS

#include "scheme_structs.h"
#include "symbol_struct.h"

scheme_value *get_symbol(char *symbol_name);

void init_symbols();
#endif
