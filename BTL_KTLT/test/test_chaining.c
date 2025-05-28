#include "Chaining.h"
#include <stdio.h>
#include <stdlib.h>

// Kiểm thử hàm so sánh xâu
void Test_CompareString (){
    char *a = "abcdefg";
    char *b = "abcdef";
    int k = CompareString(a,b);
    if (k <= 0) // tức xâu a <= xâu b
        printf("Ham CompareString của Chaining.h sai\n");
    else
        printf("Ham CompareString cua Chaining.h dung\n");
}

int main(){
    Test_CompareString();
    system("PAUSE");
    return 0;
}