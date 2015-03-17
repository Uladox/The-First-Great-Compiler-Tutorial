#include "scheme_utils.h"

void clear_file(char *filename)
{
    fclose(fopen(filename, "w"));
}

void start_prog(FILE *out)
{
  fprintf(out,
	  "    .text" "\n"
	  "    .globl scheme_entry" "\n"
	  "    .type scheme_entry, @function" "\n"
	  "scheme_entry:" "\n");
}

void end_prog(FILE *out)
{
  fprintf(out,
	  "    ret" "\n");
}

void insert_prog(FILE *out, ptr value)
{
  fprintf(out,
	  "    movl $%i, %%eax" "\n",
	  value);
}

void fxadd1(FILE *out)
{
  fprintf(out,
	  "    addl $%i, %%eax" "\n",
	  scheme_int(1));

}

void fxsub1(FILE *out)
{
  fprintf(out,
	  "    subl $%i, %%eax" "\n",
	  scheme_int(1));
	  
}

void fixnum_char(FILE *out)
{
  fprintf(out,
	  "    shll $%i, %%eax" "\n"
	  "    orl $%i, %%eax" "\n",
	  fx_tag_shift - int_tag_shift,
	  char_tag);
}

void is_zero(FILE *out)
{
  fprintf(out,
	  "    cmp $%i, %%eax" "\n"
	  "    je 1f" "\n"
	  "    movl $%i, %%eax" "\n"
	  "    jmp 2f" "\n"
	  "1:" "\n"
	  "    movl $%i, %%eax" "\n"
	  "2:" "\n",
	  scheme_int(0),
	  bool_f,
	  bool_t);
}
void is_null(FILE *out)
{
  fprintf(out,
	  "    cmp $%i, %%eax" "\n"
	  "    je 1f" "\n"
	  "    movl $%i, %%eax" "\n"
	  "    jmp 2f" "\n"
	  "1:" "\n"
	  "    movl $%i, %%eax" "\n"
	  "2:" "\n",
	  nil,
	  bool_f,
	  bool_t);
	  
}

void not(FILE *out)
{
  fprintf(out,
	  "    xorl $%i, %%eax" "\n",
	  bool_bit);
}

void is_bool(FILE *out)
{
  /* Note, this uses local symbols in
     the form of number:, this is gas syntax
     to insure unique names. FASM users
     might be familiar with using the @
     sign
  */
  fprintf(out,
	  "    cmp $%i, %%eax" "\n"
	  "    je 1f" "\n"
	  "    cmp $%i, %%eax" "\n"
	  "    je 1f" "\n"
	  "    movl $%i, %%eax" "\n"
	  "    jmp 2f" "\n"
	  "1:" "\n"
	  "    movl $%i, %%eax" "\n"
	  "2:" "\n",
	  bool_t,
	  bool_f,
	  bool_f,
	  bool_t);
}

void is_fixnum(FILE *out)
{
  fprintf(out,
	  "    and $%i, %%al" "\n"
	  "    cmp $%i, %%al" "\n"
	  "    sete %%al" "\n"
	  "    movzbl %%al, %%eax" "\n"
	  "    sal $%i, %%al" "\n"
	  "    or $%i, %%al" "\n",
	  int_tag_mask,
	  int_tag,
	  bool_bit_pos,
	  bool_f);
}

void is_char(FILE *out)
{
  fprintf(out,
	  "    cmp $%i, %%al" "\n"
	  "    sete %%al" "\n"
	  "    movzbl %%al, %%eax" "\n"
	  "    sal $%i, %%al" "\n"
	  "    or $%i, %%al" "\n",
	  char_tag,
	  bool_bit_pos,
	  bool_f);
	  
}


int main()
{
  FILE *out;
  clear_file("output.s");
  out = fopen("output.s", "a");
  start_prog(out);
  insert_prog(out, scheme_int(0));
  is_zero(out);
  end_prog(out);
  fclose(out);
  return 0;
}
