#include <stdio.h>

#include "scheme_utils.h"

extern ptr scheme_entry();

static void print_ptr(ptr x){
    if((x & int_tag_mask) == int_tag){
        printf("%d", ((int)x) >> int_tag_shift);
    } else if(x == bool_f){
        printf("#f");
    } else if(x == bool_t){
        printf("#t");
    } else if (x == nil){
        printf("'()");    
    } else if(GET_TAG(x) == char_tag) {
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
