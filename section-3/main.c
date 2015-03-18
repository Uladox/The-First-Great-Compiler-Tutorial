#include "compiler.h"
#include "symbols.h"

void main(void)
{
  init_symbols();
  printf("%s\n", get_symbol("nil")->value.symbol.symbol_name);
}
