#include <stdio.h>
#include <stdlib.h>

#include "scheme_constants.h"

ptr scheme_char(char c)
{
    return (c<<fx_tag_shift)|fx_char;
}

ptr scheme_int(int i)
{
  return i << fx_int_shift;
}

int main()
{
  FILE * out;
  out = fopen ("output.s", "w");
  fprintf(out,
"    .text" "\n"
"    .globl scheme_entry" "\n"
"    .type scheme_entry, @function" "\n"
"scheme_entry:" "\n"
"    movl $%i, %%eax" "\n"
"    ret" "\n"
	  , scheme_int(55));
  fclose(out);
  return 0;
}
