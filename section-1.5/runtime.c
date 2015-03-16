#include <stdio.h>

#include "scheme_constants.h"

extern ptr scheme_entry();

static void print_ptr(ptr x){
    if((x & fx_int_mask) == fx_int){
        printf("%d", ((int)x) >> fx_int_shift);
    } else if(x == bool_f){
        printf("#f");
    } else if(x == bool_t){
        printf("#t");
    } else if (x == nil){
        printf("'()");    
    } else if((x<<24)>>24 == fx_char) {
        printf("%c", ((int)x) >> fx_tag_shift);   
    } else {
        printf("#<unknown 0x%08x>", x);
    }
    printf("\n");
}
int main(int argc, char** argv){
    print_ptr(scheme_entry());
    return 0;
}
