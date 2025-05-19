#include"data.h"
#include<Hash.h>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>

//them sinh vien vao bang bam
void Insert_Hash_Data_Student (Student *student) {
    int index = hash(&(student->Student_Id)); // Tinh toan chi so bam
    if (Table_Students[index] == NULL) { // Neu vi tri trong, them vao
        Table_Students[index] = student;
    } else {
        Student *temp = Table_Students[index]; 
        while (temp->Next != NULL) { // Xu ly xung dot
            temp = temp->Next;
        }
        temp->Next = student; 
    }
}

//doc du lieu va them vao bang bam
void Load_Data_Student(const char *filename) {
    FILE *f = fopen(filename, "r"); // Tao con tro tep
    if (f == NULL) { // Kiem tra xem tep co mo thanh cong khong
        printf("Error opening file\n");
        return;
    }
    char line[200]; // Bien tam de doc tung dong
    while (fgets(line, sizeof(line), f)) { // Doc tung dong
        Student *student = (Student *)malloc(sizeof(Student));
        sscanf(line, "%[^,],%[^,],%d/%d/%d,%[^,],%d", student->Student_Id, student->Student_Name, &student->Date.tm_year, &student->Date.tm_mon, &student->Date.tm_mday, student->Class, &student->Number_Of_Subjects);
        student->Next = NULL;

        // Them vao bang bam
        Insert_Hash_Data_Student(student);
    }
    fclose(f); // Dong tep
}

//tim kiem sinh vien trong bang bam
void search_student(char *student_id){
    int index = hash(student_id); //tinh toan chi so bam
    Student *temp = Table_Students[index];// con tro bat dau tu dau danh sach
    while(temp != NULL){
        if(strcmp(&(temp->Student_Id), student_id) == 0) //tim duoc sinh vien}
            break; //dung vong lap
            temp = temp ->Next; //chuyen den sinh vien tiep theo    
}
 return temp; //tra ve con tro hoac NULL neu khong thay
}

//ghi lai du lieu vao tep
void Write_Student_Data(const char *filename) {
    FILE *f = fopen(filename, "w"); // Tao con tro tep
    if (f == NULL) { // Kiem tra xem tep co mo thanh cong khong
        printf("Error opening file\n");
        return;
    }
    for (int i = 0; i < MAX_TABLE_STUDENTS; i++) { // Duyet qua bang bam
        Student *temp = Table_Students[i]; // Con tro bat dau tu dau danh sach
        while (temp != NULL) {
            fprintf(f, "%s,%s,%d/%d/%d,%s,%d\n", temp->Student_Id, temp->Student_Name, temp->Date.tm_year, temp->Date.tm_mon, temp->Date.tm_mday, temp->Class, temp->Number_Of_Subjects); 
            temp = temp->Next; // Chuyen den sinh vien tiep theo
        }
    }
    fclose(f); // Dong tep
}

//xoa sinh vien khoi danh sach
void Delete_Student (char *student_id) {
    int index = hash(student_id); // Tinh toan chi so bam
    Student *temp = Table_Students[index]; // Con tro bat dau tu dau danh sach
    Student *prev = NULL; // Con tro truoc sinh vien hien tai
    while (temp != NULL) {
        if (strcmp(&(temp->Student_Id), student_id) == 0) { // Tim thay sinh vien
            if (prev == NULL) { // Neu sinh vien la phan tu dau tien
                Table_Students[index] = temp->Next; // Cap nhat vi tri trong bang bam
            } else {
                prev->Next = temp->Next; // Cap nhat con tro truoc
            }
            free(temp); // Giai phong bo nho
            return;
        }
        prev = temp; // Cap nhat con tro truoc
        temp = temp->Next; // Chuyen den sinh vien tiep theo
    }
}

//cap nhat thong tin sinh vien
void Update_Student (char *student_id, Student *new_student) {
    int index = hash(student_id); // Tinh toan chi so bam
    Student *temp = Table_Students[index]; // Con tro bat dau tu dau danh sach
    while (temp != NULL) {
        if (strcmp(&(temp->Student_Id), student_id) == 0) { // Tim thay sinh vien
            strcpy(temp->Student_Name, new_student->Student_Name); // Cap nhat ten sinh vien
            temp->Date = new_student->Date; // Cap nhat ngay sinh
            strcpy(temp->Class, new_student->Class); // Cap nhat lop
            temp->Number_Of_Subjects = new_student->Number_Of_Subjects; // Cap nhat so mon hoc
            return;
        }
        temp = temp->Next; // Chuyen den sinh vien tiep theo
    }
}