#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Student.h"
#include "Hash.h"
#include "Chaining.h"

// Khai báo bảng băm toàn cục
Chaining* Table_Students[MAX_TABLE_STUDENTS] = {NULL};

// In thong tin sinh vien
void In_Thong_Tin_Sinh_Vien(Student* sv) {
    printf("ID: %s | Ten: %s | Lop: %s | Ngay sinh: %02d/%02d/%04d | So mon: %d | GPA: %.2f | Xep loai: %s\n",
        sv->Student_Id, sv->Student_Name, sv->Class,
        sv->Date.tm_mday, sv->Date.tm_mon, sv->Date.tm_year,
        sv->Number_Of_Subjects, sv->GPA, sv->Rank);
    for (int i = 0; i < sv->Number_Of_Subjects; i++) {
        printf("  - Mon: %s | Diem: %.2f\n", sv->Grades[i].Subject_Id, sv->Grades[i].Score);
    }
}

int main() {
    printf("=== TEST THEM SINH VIEN VA DIEM SO ===\n");

    Student* sv1 = malloc(sizeof(Student));
    strcpy(sv1->Student_Id, "SV001");
    strcpy(sv1->Student_Name, "Nguyen Van A");
    sv1->Date.tm_mday = 15;
    sv1->Date.tm_mon = 6;
    sv1->Date.tm_year = 2002;
    strcpy(sv1->Class, "CTK44");
    sv1->GPA = 3.5;
    strcpy(sv1->Rank, "Gioi");
    sv1->Number_Of_Subjects = 2;
    strcpy(sv1->Grades[0].Subject_Id, "CTDL");
    sv1->Grades[0].Score = 8.0;
    strcpy(sv1->Grades[1].Subject_Id, "PTTKTT");
    sv1->Grades[1].Score = 9.0;

    Insert_Hash_Data_Student(sv1);

    printf("-> Da them sinh vien: %s\n", sv1->Student_Id);

    printf("\n=== TEST TIM KIEM SINH VIEN ===\n");
    Chaining* node = Search_Student("SV001");
    if (node != NULL) {
        printf("Tim thay sinh vien co ID SV001:\n");
        In_Thong_Tin_Sinh_Vien((Student*)node->Data);
    } else {
        printf("Khong tim thay sinh vien co ID SV001\n");
    }

    printf("\n=== TEST CAP NHAT SINH VIEN ===\n");
    Student* sv_update = malloc(sizeof(Student));
    strcpy(sv_update->Student_Id, "SV001");
    strcpy(sv_update->Student_Name, "Nguyen Van B");
    sv_update->Date.tm_mday = 20;
    sv_update->Date.tm_mon = 7;
    sv_update->Date.tm_year = 2002;
    strcpy(sv_update->Class, "CTK44A");
    sv_update->GPA = 3.8;
    strcpy(sv_update->Rank, "Xuat sac");
    sv_update->Number_Of_Subjects = 1;
    strcpy(sv_update->Grades[0].Subject_Id, "CTDL");
    sv_update->Grades[0].Score = 9.5;

    Update_Student(sv_update);
    printf("-> Da cap nhat thong tin sinh vien SV001\n");

    node = Search_Student("SV001");
    if (node != NULL) {
        printf("Thong tin sau cap nhat:\n");
        In_Thong_Tin_Sinh_Vien((Student*)node->Data);
    }

    printf("\n=== TEST XOA SINH VIEN ===\n");
    Delete_Student("SV001");
    printf("-> Da xoa sinh vien co ID SV001\n");

    node = Search_Student("SV001");
    if (node == NULL) {
        printf("Khong tim thay sinh vien SV001 sau khi xoa\n");
    } else {
        printf("Xoa khong thanh cong\n");
    }

    printf("\n=== TEST KET THUC ===\n");
    system("PAUSE");
    return 0;
}
