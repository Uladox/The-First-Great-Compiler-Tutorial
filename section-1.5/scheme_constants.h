#ifndef SCHEME_COSTANTS
#define SCHEME_COSTANTS

/* define all scheme constants */
#define bool_f 0x2F
#define bool_t 0x6F
#define nil 0x3F
/* define some shifting constants*/
#define fx_int_shift 2
#define fx_tag_shift 8
/* define some tags for types */
//ints are special so they hold more
//since only they last two bits are
//used for type
#define fx_int_mask 0x03
#define fx_int 0x00
#define fx_char 0x0F

/*
0000 0000 0000 0000 0000 0000 0010 1111
0000 0000 0000 0000 0000 0000 0110 1111
0000 0000 0000 0000 0000 0000 0000 0011
0000 0000 0000 0000 0000 0000 0000 0000
*/
/* all scheme values are of type ptrs */

typedef unsigned int ptr;

#endif
