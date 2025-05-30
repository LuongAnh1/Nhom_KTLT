#include <stdio.h>
#include <stdlib.h>
#include "Data.h"
#include "Subject.h"
#include "Hash.h"
#include "Student.h"

Chaining *Table_Subjects[MAX_TABLE_SUBJECTS] = {NULL}; // Mảng danh sách môn học
Chaining *Table_Students[MAX_TABLE_STUDENTS] = {NULL}; // Mảng danh sách sinh viên
int main(){
    Load_Data_Subject("data/Subject.csv"); // Đọc dữ liệu môn học từ tệp
    Load_Data_Student("data/Student.csv"); // Đọc dữ liệu sinh viên từ tệp
    Load_Data_Grades("data/Grades.csv"); // Đọc dữ liệu điểm số từ tệp 
    return 0;
}