#ifndef SERVICE_H
#define SERVICE_H
#include "Data.h"
//Cường
// Xếp loại sinh viên
void RankStudent(Student* Student);
// Trung bình điểm của sinh viên (được gọi trong hàm InsertGrades)
void AvgGrades(Student* Student);
// Nhập điểm cho sinh viên
void InsertGrades(Grades *Grades, char Student_id);
//-------------------------------------------------------------
// Sắp xếp danh sách sinh viên theo điểm trung bình
void SortStudentByGPA();
// Tìm kiếm sinh viên theo mã sinh viên
void SearchStudentById();
// Tìm kiếm sinh viên theo tên sinh viên
void SearchStudentByName();

#endif