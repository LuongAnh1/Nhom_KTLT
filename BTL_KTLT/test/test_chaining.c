#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Chaining.h"

// Hàm hỗ trợ: In danh sách liên kết
void InDanhSach(Chaining* head) {
    printf("Output: Danh sach hien tai: ");
    Chaining* curr = head;
    while (curr != NULL) {
        printf("%s ", (char*)curr->Key);
        curr = curr->Next;
    }
    printf("\n");
}

// Hàm test các thao tác chính
int main() {
    Chaining* head = NULL;
    char* key1 = strdup("hoa");
    char* data1 = strdup("data1");
    char* key2 = strdup("an");
    char* data2 = strdup("data2");
    char* key3 = strdup("binh");
    char* data3 = strdup("data3");

    printf("Input: Them vao 'hoa', 'an', 'binh' vao danh sach\n");
    head = Insert(head, data1, key1);
    head = Insert(head, data2, key2);
    head = Insert(head, data3, key3);
    InDanhSach(head);

    printf("Input: Tim kiem khoa 'an'\n");
    Chaining* found = Search(head, "an");
    if (found) {
        printf("Output: Tim thay khoa 'an': %s\n", (char*)found->Data);
    } else {
        printf("Output: Khong tim thay khoa 'an'\n");
    }

    printf("Input: Xoa khoa 'hoa'\n");
    head = Delete(head, "hoa");
    InDanhSach(head);

    printf("Input: Xoa khoa 'nam' (khong ton tai)\n");
    head = Delete(head, "nam");
    InDanhSach(head);

    // Giai phong bo nho
    while (head != NULL) {
        Chaining* tmp = head;
        head = head->Next;
        free(tmp->Key);
        free(tmp->Data);
        free(tmp);
    }
    system("PAUSE");
    return 0;
}