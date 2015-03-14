#include <stdio.h>

/* define all scheme constants */
#define bool_f 0x2F
#define bool_t 0x6F
#define nil 0x3F
#define fx_mask 0x03
#define fx_char 0x0F
#define fx_int 0x00
#define fx_shift 2
#define fx_tag_shift 8
/*
0000 0000 0000 0000 0000 0000 0010 1111
0000 0000 0000 0000 0000 0000 0110 1111
0000 0000 0000 0000 0000 0000 0000 0011
0000 0000 0000 0000 0000 0000 0000 0000
*/
/* all scheme values are of type ptrs */
typedef unsigned int ptr;

extern ptr scheme_entry();

ptr scheme_char(char c)
{
    return (c<<fx_tag_shift)|fx_char;
}
static void print_ptr(ptr x){
    if((x & fx_mask) == fx_int){
        printf("%d", ((int)x) >> fx_shift);
    } else if((x<<24)>>24 == fx_char) {
        printf("%c", ((int)x) >> fx_tag_shift);   
    } else if(x == bool_f){
        printf("#f");
    } else if(x == bool_t){
        printf("#t");
    } else if (x == nil){
        printf("'()");    
    } else {
        printf("#<unknown 0x%08x>", x);
    }
    printf("\n");
}
int main(int argc, char** argv){
    print_ptr(scheme_entry());
    return 0;
}
