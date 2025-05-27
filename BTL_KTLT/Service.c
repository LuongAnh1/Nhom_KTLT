#include "Service.h"
#include "Hash.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "Chaining.h"

//Quy doi diem
void ChangeGrade(Grades* grades) {
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

//Tim tin chi cua mon hoc qua Subject_Id
int GetCreditsBySubjectId(int Subject_Id) {
    for (int i = 0; i < MAX_TABLE_SUBJECTS; i++) {
        if (Table_Subjects[i] != NULL) {
            Subject* subject = (Subject*)Table_Subjects[i]->Data;
            if (subject->Subject_Id == Subject_Id) {
                return subject->Credits;
            }
        }
    }
    return -1; // Khong tim thay mon hoc
}

//Tinh diem trung binh cua sinh vien
void AvgGrades(Student* student) {
    float totalScore = 0.0;
    int totalCredits = 0;

    for (int i = 0; i < student->Number_Of_Subjects; i++) {
        int credits = GetCreditsBySubjectId(student->Grades[i].Subject_Id);
        if (credits != -1) {
            ChangeGrade(&student->Grades[i]); // Quy đổi điểm
            totalScore += student->Grades[i].Score * credits;
            totalCredits += credits;
        }
    }

    if (totalCredits > 0) {
        student->GPA = totalScore / totalCredits;
    } else {
        student->GPA = 0.0; // Không có môn học nào
    }
}





    


