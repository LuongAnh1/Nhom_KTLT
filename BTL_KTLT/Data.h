#ifndef DATA
#define DATA
#include <time.h>
#define MAX_TABLE_STUDENTS 50 // Kích thước bảng băm sinh viên
#define MAX_TABLE_SUBJECTS 50 // Kích thước bảng băm môn học
#define MAX_SUBJECTS 20 // Số lượng môn mà 1 kỳ sinh viên có thể học tối đa
// Bảng danh sách môn học
struct Subject{
    char Subject_Id[10]; // Mã môn học
    char Subject_Name[50]; // Tên môn học
    int Credits; // Số tín chỉ
};
typedef struct Subject Subject;
// Điểm
struct Grades{
    char Subject_Id[10]; // Mã môn học
    float Score; // Điểm gốc (0-10)
};
typedef struct Grades Grades;
// Bảng học sinh
struct Student{
    char Student_Id[10]; // Mã sinh viên
    char Student_Name[50]; // Tên sinh viên
    struct tm Date; // Ngày sinh
    char Class[10]; // Lớp
    int Number_Of_Subjects; // Số môn học
    Grades Grades[MAX_SUBJECTS]; // Điểm từng môn
    float GPA; // Điểm trung bình của kỳ
    char Rank[10]; // Học lực (Kém, Yếu, Trung bình, Khá Giỏi, Xuất sắc)
};
typedef struct Student Student;

// Tạo chuỗi
struct Chaining{
    void *Key; // Khóa
    void *Data; // Dữ liệu  
    struct Chaining *Next; // Con trỏ đến phần tử tiếp theo
};
typedef struct Chaining Chaining;

// Cấu trúc cho phần tử heap
typedef struct HeapNode {
    Chaining* node; // Con trỏ tới node hiện tại trong mỗi danh sách
    int listIndex;  // Chỉ số của danh sách 
} HeapNode;


// Khai báo biến toàn cục (bảng bămbăm)
extern Chaining *Table_Subjects[MAX_TABLE_SUBJECTS]; // Mảng danh sách môn học
extern Chaining *Table_Students[MAX_TABLE_STUDENTS]; // Mảng danh sách sinh viên
#endif