#include "Student.h"
#include "Hash.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "Chaining.h"

//them sinh vien vao bang bam
void Insert_Hash_Data_Student (Student *student) {
    int index = hash(student->Student_Id); // Tinh toan chi so bam
    Table_Students[index] = Insert(Table_Students[index], student, student->Student_Id); // Them sinh vien vao danh sach lien ket
}

//doc du lieu sinh viên va them vao bang bam
void Load_Data_Student(const char *filename) {
    FILE *f = fopen(filename, "r"); // Tao con tro tep
    if (f == NULL) { // Kiem tra xem tep co mo thanh cong khong
        printf("Khong mo duoc file %s\n", filename);
        return;
    }
    char line[200]; // Dung de doc tung dong
    line[strcspn(line, "\n")] = '\0'; // Xóa ký tự xuống dòng nếu có
    while (fgets(line, sizeof(line), f) != NULL ) { // Doc tung dong
        // Nếu dòng chỉ chứa ký tự newline (dòng trống)
        if (strcmp(line, "\n") == 0)
            continue;
        Student *student = (Student *)malloc(sizeof(Student));
        sscanf (line, "%[^,],%[^,],%d/%d/%d,%[^,],%d", 
               student->Student_Id, student->Student_Name, 
               &student->Date.tm_mday, &student->Date.tm_mon, &student->Date.tm_year,
               student->Class, &student->GPA, student->Rank); 
        student->Number_Of_Subjects = 0;
        // Them vao bang bam
        Insert_Hash_Data_Student(student); 
    }
    fclose(f); // Dong tep
}

// Đọc dữ liệu điểm số và thêm vào danh sách
void Load_Data_Grades(const char *filename){
    FILE *f = fopen(filename, "r"); // Tao con tro tep
    if (f == NULL) { // Kiem tra xem tep co mo thanh cong khong
        printf("Khong mo duoc file %s\n", filename);
        return;
    }
    char line[200]; // Dung de doc tung dong
    while (fgets(line, sizeof(line), f) != NULL ) { // Doc tung dong
        // Nếu dòng chỉ chứa ký tự newline (dòng trống)
        if (strcmp(line, "\n") == 0)
            continue;
        line[strcspn(line, "\n")] = '\0'; // Xóa ký tự xuống dòng nếu có
        char student_id[10], subject_id[10];
        float score;
        sscanf (line, "%[^,],%[^,],%f", student_id, subject_id, &score);
        Student* student = Search_Student(student_id)->Data;
        student->Grades[student->Number_Of_Subjects].Score = score;
        strcpy(student->Grades[student->Number_Of_Subjects].Subject_Id, subject_id);
        student->Number_Of_Subjects++;
    }
}

//tim kiem sinh vien trong bang bam
Chaining* Search_Student(char *student_id){
    int index = hash(student_id); //tinh toan chi so bam
    return Search(Table_Students[index], student_id); //tim kiem sinh vien
}

//ghi lai du lieu sinh vien vao tep
void Write_Student_Data(const char *filename) {
    FILE *f = fopen(filename, "w"); // Tao con tro tep
    if (f == NULL) { // Kiem tra xem tep co mo thanh cong khong
        printf("Khong mo duoc file %s\n", filename);
        return;
    }
    for (int i = 0; i < MAX_TABLE_STUDENTS; i++) { // Duyet qua tat ca cac chi so bam
        Chaining *temp = Table_Students[i]; // Lay danh sach lien ket tai chi so bam
        while (temp != NULL) { // Duyet qua danh sach lien ket
            Student *student = (Student *)temp->Data; // Lay du lieu sinh vien
            fprintf(f, "%s,%s,%d/%d/%d,%s,%d\n", 
                    student->Student_Id, student->Student_Name, 
                    student->Date.tm_year, student->Date.tm_mon, student->Date.tm_mday,
                    student->Class, student->Number_Of_Subjects); // Ghi du lieu vao tep
            Write_Grades_Data("data/Subject.csv", student);
            temp = temp->Next; // Di chuyen den nut tiep theo
        }
    }
    fclose(f); // Dong tep
}

// Ghi laị dữ liệu điểm số vào tệp
void Write_Grades_Data(const char *filename, Student* student){
    FILE *f = fopen(filename, "w"); // Tao con tro tep
    for (int i = 0; i < student->Number_Of_Subjects; i++)
        fprintf(f, "%s,%s,%f\n", student->Student_Id, 
                student->Grades[i].Subject_Id,
                student->Grades[i].Score);
    free(f);
}
//xoa sinh vien khoi danh sach
void Delete_Student(char *student_id) {
    int index = hash(student_id); // Tinh toan chi so bam
    Table_Students[index] = Delete(Table_Students[index], student_id); // Xoa sinh vien khoi danh sach lien ket
}

//cap nhat thong tin sinh vien 
void Update_Student(Student *student) {
    int index = hash(student->Student_Id); // Tinh toan chi so bam
    Chaining *node = Search(Table_Students[index], student->Student_Id); // Tim kiem sinh vien trong bang bam
    if (node != NULL) { // Neu tim thay sinh vien
        Student *existing_student = (Student *)node->Data; // Lay du lieu sinh vien hien tai
        // Cap nhat thong tin sinh vien
        strcpy(existing_student->Student_Name, student->Student_Name);
        existing_student->Date = student->Date;
        strcpy(existing_student->Class, student->Class);
        existing_student->Number_Of_Subjects = student->Number_Of_Subjects;
        for (int i = 0; i < student->Number_Of_Subjects; i++) {
            existing_student->Grades[i] = student->Grades[i];
        }
        existing_student->GPA = student->GPA;
        strcpy(existing_student->Rank, student->Rank);
    }
}