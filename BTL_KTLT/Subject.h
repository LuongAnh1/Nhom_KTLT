#ifndef SUBJECT_H
#define SUBJECT_H
#include "Data.h"

void Load_Data_Subject(const char *filename);
// Tìm kiếm môn học trong bảng băm
Chaining* Search_Subject (char *subject_id);
// Ghi lại dữ liệu vào tệp
void Write_Subject_Data(const char *filename);
// Thêm môn học vào bảng băm
void Insert_Grade_Subject(Subject *subject, int index);

#endif