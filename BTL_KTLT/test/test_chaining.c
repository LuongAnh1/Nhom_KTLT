#include "Chaining.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
// Kiểm thử với các hàm còn lại
void Test_CreatNode_Insert_Search_Delete(){
    // Tạo 1 data bất kỳ kèm key
    Chaining *head=NULL;
    int data1=10, data2=11;
    char* key1 = "abc";
    char* key2 = "def";

    // Nếu không chạy qua đoạn này tức Insert lỗilỗi
    head = Insert(head,&data1,key1);
    head = Insert(head,&data2,key2);
    // Test Search
    Chaining *find = Search(head,key1);
    if (find != NULL && strcmp(find->Key,key1) == 0)
        printf("Ham Search cua Chaining.d dung\n");
    else
        printf("Ham Search cua Chaining.h sai\n");
    // Test Delete
    head = Delete(head,key2);
    Chaining *find2 = Search(head,key2);
    printf("Hihi");
    
    if (find2 == NULL) 
        printf("Ham Delete cua Chaining.h dung\n");
    else
        printf("Ham Delete cua Chaining.h sai\n");
}

int main(){
    Test_CompareString();
    Test_CreatNode_Insert_Search_Delete();
    system("PAUSE");
    return 0;
}