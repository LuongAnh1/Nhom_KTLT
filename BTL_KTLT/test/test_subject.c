#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Subject.h"
#include "Chaining.h"

Chaining *Table_Subjects[MAX_TABLE_SUBJECTS] = {NULL}; // Mảng danh sách môn học
void InMotMonHoc(Subject *subject) {
    if (subject)
        printf("Ma: %s, Ten: %s, So tin chi: %d\n", subject->Subject_Id, subject->Subject_Name, subject->Credits);
}

void InBangMonHoc() {
    printf("Output: Danh sach mon hoc hien tai:\n");
    for (int i = 0; i < MAX_TABLE_SUBJECTS; ++i) {
        Chaining *curr = Table_Subjects[i];
        while (curr != NULL) {
            InMotMonHoc((Subject*)curr->Data);
            curr = curr->Next;
        }
    }
}

int main() {
    // Xoa bang bam truoc khi test
    for (int i = 0; i < MAX_TABLE_SUBJECTS; ++i) Table_Subjects[i] = NULL;

    // Test them mon hoc
    printf("\n=== TEST THEM MON HOC ===\n");
    Subject *sub1 = (Subject*)malloc(sizeof(Subject));
    strcpy(sub1->Subject_Id, "MH01"); strcpy(sub1->Subject_Name, "Toan"); sub1->Credits = 3;

    Subject *sub2 = (Subject*)malloc(sizeof(Subject));
    strcpy(sub2->Subject_Id, "MH02"); strcpy(sub2->Subject_Name, "Van"); sub2->Credits = 2;

    printf("Input: Them mon hoc MH01 - Toan, 3 tin chi\n");
    Insert_Hash_Data_Subject(sub1);
    printf("Input: Them mon hoc MH02 - Van, 2 tin chi\n");
    Insert_Hash_Data_Subject(sub2);
    InBangMonHoc();

    // Test ghi va doc file
    printf("\n=== TEST GHI FILE ===\n");
    printf("Input: Ghi du lieu mon hoc ra file 'test_subject.csv'\n");
    Write_Subject_Data("test_subject.csv");
    printf("Output: Ghi file thanh cong\n");

    // Xoa bang va doc lai tu file
    printf("\n=== TEST DOC FILE ===\n");
    for (int i = 0; i < MAX_TABLE_SUBJECTS; ++i) Table_Subjects[i] = NULL;
    printf("Input: Nap lai du lieu tu file 'test_subject.csv'\n");
    Load_Data_Subject("test_subject.csv");
    InBangMonHoc();

    // Test tim kiem
    printf("\n=== TEST TIM KIEM ===\n");
    printf("Input: Tim kiem mon hoc co ma MH01\n");
    Chaining *found = Search_Subject("MH01");
    if (found) {
        printf("Output: Tim thay mon hoc:\n");
        InMotMonHoc((Subject*)found->Data);
    } else {
        printf("Output: Khong tim thay mon hoc\n");
    }

    printf("Input: Tim kiem mon hoc co ma MH10\n");
    found = Search_Subject("MH10");
    if (found) {
        printf("Output: Tim thay mon hoc:\n");
        InMotMonHoc((Subject*)found->Data);
    } else {
        printf("Output: Khong tim thay mon hoc\n");
    }
    system("PAUSE");
    return 0;
}