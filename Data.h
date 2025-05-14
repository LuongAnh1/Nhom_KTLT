#ifndef DATA
#define DATA
#include <time.h>
#define MAX_TABLE_STUDENTS 50 // Kích thước bảng băm sinh viên
#define MAX_TABLE_SUBJECTS 50 // Kích thước bảng băm môn học
#define MAX_SUBJECTS 20 // Số lượng môn mà 1 kỳ sinh viên có thể học tối đa
// Bảng danh sách môn học
struct Subject{
    int Subject_Id; // Mã môn học
    char Subject_Name[50]; // Tên môn học
    int Credits; // Số tín chỉ
};
typedef struct Subject Subject;
// DiểmDiểm
struct Grades{
    int Subject_Id; // Mã môn học
    float Score; // Điểm
};
typedef struct Grades Grades;
// Bảng học sinh
struct Student{
    int Student_Id; // Mã sinh viên
    char Student_Name[50]; // Tên sinh viên
    struct tm Date; // Ngày sinh
    char Class[10]; // Lớp
    int Number_Of_Subjects; // Số môn học
    Grades Grades[MAX_SUBJECTS]; // Điểm từng môn
    float GPA; // Điểm trung bình của kỳ
    char Rank[10]; // Học lực
};
typedef struct Student Student;

// Khai báo biến toàn cục
extern Subject Table_Subjects[MAX_TABLE_SUBJECTS]; // Mảng danh sách môn học
extern Student Table_Students[MAX_TABLE_STUDENTS]; // Mảng danh sách sinh viên
#endif