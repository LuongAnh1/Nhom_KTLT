#include "Student.h"
#include "Hash.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "Chaining.h"

//them sinh vien vao bang bam
void Insert_Hash_Data_Student (Student *student) {
    int index = hash(&(student->Student_Id)); // Tinh toan chi so bam
    Table_Students[index] = Insert(Table_Students[index], student, student->Student_Id); // Them sinh vien vao danh sach lien ket
}

//doc du lieu va them vao bang bam
void Load_Data_Student(const char *filename) {
    FILE *f = fopen(filename, "r"); // Tao con tro tep
    if (f == NULL) { // Kiem tra xem tep co mo thanh cong khong
        printf("Khong mo duoc file %s\n", filename);
        return;
    }
    char line[200]; // Dung de doc tung dong
    while (fgets(line, sizeof(line), f)) { // Doc tung dong
        Student *student = (Student *)malloc(sizeof(Student));
        sscanf (line, "%[^,],%[^,],%d/%d/%d,%[^,],%d", 
               student->Student_Id, student->Student_Name, 
               &student->Date.tm_mday, &student->Date.tm_mon, &student->Date.tm_year,
               student->Class, &student->Number_Of_Subjects); 
        // Them vao bang bam
        Insert_Hash_Data_Student(student); 
    }
    fclose(f); // Dong tep
}

//tim kiem sinh vien trong bang bam
Chaining* Search_Student(char *student_id){
    int index = hash(student_id); //tinh toan chi so bam
    return Search(Table_Students[index], student_id); //tim kiem sinh vien
}

//ghi lai du lieu vao tep
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
            temp = temp->Next; // Di chuyen den nut tiep theo
        }
    }
    fclose(f); // Dong tep
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