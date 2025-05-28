#include "Service.h"
#include "Hash.h"
#include "Chaining.h"
#include "MergeSort.h"
#include "Min-Heap.h"
#include "Subject.h"
#include "Student.h"

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

//Quy doi diem
void ExchangeGrade(Grades* grades) {
    if (grades->Score >= 8.5 && grades->Score <= 10.0) {
        grades->Score = 4.0;
    } else if (grades->Score >= 8.0 && grades->Score < 8.5) {
        grades->Score = 3.5;
    } else if (grades->Score >= 7.0 && grades->Score < 8.0) {
        grades->Score = 3.0;
    } else if (grades->Score >= 6.5 && grades->Score < 7.0) {
        grades->Score = 2.5;
    } else if (grades->Score >= 5.5 && grades->Score < 6.5) {
        grades->Score = 2.0;
    } else if (grades->Score >= 5.0 && grades->Score < 5.5) {
        grades->Score = 1.5;
    } else if (grades->Score >= 4.0 && grades->Score < 5.0) {
        grades->Score = 1.0;
    } else {
        grades->Score = 0.0; 
    }
}

//Xep loai sinh vien
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

//Tinh diem trung binh cua sinh vien
void AvgGrades(Student* student) {
    float totalScore = 0.0;
    int totalCredits = 0;

    for (int i = 0; i < student->Number_Of_Subjects; i++) {
        Grades* grades = &student->Grades[i];
        Chaining* subject_node = Search_Subject(grades->Subject_Id);
        if (subject_node != NULL) {
            Subject* subject = (Subject*)subject_node->Data;
            Grades temp = *grades;
            ExchangeGrade(&temp);
            totalScore += temp.Score * subject->Credits; 
            totalCredits += subject->Credits;
        }
    }

    if (totalCredits > 0) {
        student->GPA = totalScore / totalCredits;
    } else {
        student->GPA = 0.0;
    }
}

//Nhap diem cho sinh vien
void InsertGrades(char* Student_id, char* Subject_Id, float Score) {
    Chaining* node = Search_Student(Student_id); 
    if (node != NULL) {
        Student* student = (Student*)node->Data; 
        if (student->Number_Of_Subjects < MAX_SUBJECTS) {
            Grades* grades = &student->Grades[student->Number_Of_Subjects];
            strcmp(grades->Subject_Id, Subject_Id);
            grades->Score = Score;
            student->Number_Of_Subjects++;
            AvgGrades(student); //Tinh diem trung binh
            RankStudent(student); //Xep loai sinh vien
        } else {
            printf("So mon hoc da dat toi da.\n");
        }
    } else {
        printf("Khong tim thay sinh vien voi ma %s.\n", Student_id);
    }
}

// Sắp xếp danh sách sinh viên theo điểm trung bình

// Hàm in ra kết quả chung
void Sort(const char *key){
    // Sắp xếp lại các cuỗi danh sách
    for(int i = 0; i < MAX_TABLE_STUDENTS; i++)
        mergeSort(&Table_Students[i], key);
    // In ra kết quả trộn các danh sách
    KWayMerge(Table_Students, MAX_TABLE_STUDENTS, key);
}
// Sắp xếp danh sách sinh viên theo điểm trung bình
void SortStudentByGPA(){
    Sort("GPA");
}
// Sắp xếp danh sách sinh viên theo tên
void SortStudentByName(){
    Sort("Student_Name");
}
// Sắp xếp danh sách sinh viên theo MSSV
void SortStudentByID(){
    Sort("Student_Id");
}
