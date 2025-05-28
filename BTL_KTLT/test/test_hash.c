#include "Hash.h"
#include <stdlib.h>
#include <stdio.h>


void Test_Hash(){
    char *a="abcd", *b = "abc";
    unsigned int k1 = hash(a), k2 = hash(b);
    if (k1 > 0 && k2 > 0 && k1 != k2)
        printf("Ham hash cua Hash.h dung\n");
    else
        printf("Ham hash cua Hash.h sai\n");
}
int main(){
    Test_Hash();
    system("PAUSE");
    return 0;
}