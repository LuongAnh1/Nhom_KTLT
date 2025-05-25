#include "Service.h"
#include "Hash.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "Chaining.h"

//Xep loại sinh viên
void RankStudent(Student* student) {
    if (student->GPA >= 3.6 && student->GPA <= 4.0) {
        strcpy(student->Rank, "Xuat sac");
    } else if (student->GPA >= 3.2 && student->GPA < 3.6) {
        strcpy(student->Rank, "Gioi");
    } else if (student->GPA >= 2.5 && student->GPA < 3.2) {
        strcpy(student->Rank, "Kha");
    } else if (student->GPA >= 2.0 && student->GPA < 2.5) {
        strcpy(student->Rank, "Trung binh");
    } else if (student->GPA >= 1.0 && student->GPA < 2.0) {
        strcpy(student->Rank, "Yeu");
    } else {
        strcpy(student->Rank, "Kem");
    }
}

//Trung bình điểm của sinh viên
void AvgGrades(Student* student) {
//hoi khoai
}

//Nhap diem cho sinh viên (sửa lại)
void InsertGrades(char Student_id, int Subject_Id, float Score) {
    int subject_count;
    printf("Nhap so mon hoc: ");
    scanf("%d", &subject_count);
    grades->Number_Of_Subjects = subject_count;

    for (int i = 0; i < subject_count; i++) {
        printf("Nhap ten mon hoc %d: ", i + 1);
        scanf("%s", grades->Subject[i].Subject_Name);
        printf("Nhap diem mon hoc %d: ", i + 1);
        scanf("%f", &grades->Subject[i].Grade);
    }

    //Cap nhat diem trung binh va xep loai
    AvgGrades((Student*)grades);
    RankStudent((Student*)grades);
}