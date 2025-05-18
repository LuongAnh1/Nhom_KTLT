#include <stdio.h>
#include <stdlib.h>
#include "Data.h"
#include "Subject.h"

Subject *Table_Subjects[MAX_TABLE_SUBJECTS] = {NULL}; // Mảng danh sách môn học
Student *Table_Students[MAX_TABLE_STUDENTS] = {NULL}; // Mảng danh sách sinh viên
int main(){
    Load_Data_Subject("Subject.csvcsv"); // Đọc dữ liệu từ tệp
    return 0;
}