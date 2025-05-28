#include "Chaining.h"
#include "stdio.h"

// Kiểm thử hàm so sánh xâu
void Test_CompareString (){
    char *a = "ABCDEFG";
    char *b = "abcdefg";
    int k = CompareString(a,b);
    if (k <= 0) // tức xâu a <= xâu b
        printf("Hàm CompareString của Chaining.h sai\n");
    else
        printf("Hàm CompareString của Chaining.h đúng\n");
}

int main(){
    Test_CompareString();
    return 0;
}