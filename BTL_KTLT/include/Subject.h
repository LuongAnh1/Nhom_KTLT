#ifndef SUBJECT_H
#define SUBJECT_H
#include "Data.h"

// Thêm môn học vào bảng băm
void Insert_Hash_Data_Subject (Subject *subject);
// Đọc dữ liệu từ tệp và thêm vào bảng băm
void Load_Data_Subject(const char *filename);
// Tìm kiếm môn học trong bảng băm
Chaining* Search_Subject (char *subject_id);
// Ghi lại dữ liệu vào tệp
void Write_Subject_Data(const char *filename);

#endif