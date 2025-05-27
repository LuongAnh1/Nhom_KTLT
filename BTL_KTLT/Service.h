#ifndef SERVICE_H
#define SERVICE_H
#include "Data.h"
//Cường
//Quy đổi điểm của sinh viên
void ExchageGrade(Grades* grades);
// Xếp loại sinh viên
void RankStudent(Student* Student);
// Trung bình điểm của sinh viên (được gọi trong hàm InsertGrades)
void AvgGrades(Student* Student);
// Nhập điểm cho sinh viên
void InsertGrades(char Student_id, int Subject_Id, float Score);
//-------------------------------------------------------------
// Sắp xếp danh sách sinh viên theo điểm trung bình
void SortStudentByGPA();
// Sắp xếp danh sách sinh viên theo tên
void SortStudentByName();
// Sắp xếp danh sách sinh viên theo MSSV
void SortStudentByID();

#endif