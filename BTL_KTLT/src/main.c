#include <stdio.h>
#include <stdlib.h>

#include "Data.h"
#include "Chaining.h"
#include "Hash.h"
#include "MergeSort.h"
#include "Min-Heap.h"
#include "Student.h"
#include "Service.h"
#include "Subject.h"

// Khai báo bảng băm toàn cục 
Chaining *Table_Subjects[MAX_TABLE_SUBJECTS] = {NULL}; // Mảng danh sách môn học
Chaining *Table_Students[MAX_TABLE_STUDENTS] = {NULL}; // Mảng danh sách sinh viên
int main(){
    // Tải dữ liệu lên bộ nhớ 
    Load_Data_Subject("data/Subject.csv"); // Đọc dữ liệu môn học từ tệp
    Load_Data_Student("data/Student.csv"); // Đọc dữ liệu sinh viên từ tệp
    Load_Data_Grades("data/Grades.csv"); // Đọc dữ liệu điểm số từ tệp 

    // Vào MENU 
    Menu();

    // Ghi lại dữ liệu vào file .csv 
    Write_Subject_Data("data/Subject.csv"); // Ghi dữ liệu môn học
    Write_Student_Data("data/Student.csv"); // Ghi dữ liệu sinh viên (Đã bao gồm ghi cả điểm số) 
    return 0;
}