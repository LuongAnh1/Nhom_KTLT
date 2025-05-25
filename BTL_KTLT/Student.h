#ifndef STUDENT_H
#define STUDENT_H
#include "Data.h"

void Insert_Hash_Data_Student (Student *student);
void Load_Data_Student(const char *filename);
Chaining* Search_Student(char *student_id);
//ghi lai du lieu vao tep
void Write_Student_Data(const char *filename);
//xoa sinh vien khoi danh sach
void Delete_Student(char *student_id);
//cap nhat thong tin sinh vien
void Update_Student(Student *student);

#endif