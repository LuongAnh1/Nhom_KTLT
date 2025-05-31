#ifndef SUBJECT_H
#define SUBJECT_H
#include "Data.h"

void Load_Data_Subject(const char *filename);
// Tìm kiếm môn học trong bảng băm
Chaining* Search_Subject (char *subject_id);
// Ghi lại dữ liệu vào tệp
void Write_Subject_Data(const char *filename);

#endif