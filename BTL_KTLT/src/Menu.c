#include <stdio.h>
#include <stdlib.h>
#include <Hash.h>
#include <string.h>

#include "Data.h"
#include "Chaining.h"
#include "Hash.h"
#include "MergeSort.h"
#include "Min-Heap.h"
#include "Student.h"
#include "Service.h"
#include "Subject.h"

void ClearScreen(){
    printf("\033[H\033[J");
}
// Khai bao ham
void Nhap_Diem (char* student_id,char* subject_id, float* score);
void Tim_Sinh_Vien (char* student_id);
void In_Danh_Sach();
void Them_Sinh_Vien(char* student_id);
void Xoa_Sinh_Vien(char* student_id);

void Menu() {
    int choice;
    char subject_id[11]; // Mã môn học
    char student_id[11]; // Mã sinh viên
    float score; // Điểm gốc (0-10)
    do {
        ClearScreen();
        printf("=========== CHUONG TRINH QUAN LY SINH VIEN ===========\n");
        printf("1. Nhap diem cho sinh vien\n");
        printf("2. Tim kiem sinh vien\n");
        printf("3. In danh sach sinh vien\n");
        printf("4. Them sinh vien\n");
        printf("5. Xoa sinh vien\n");
        printf("0. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);
        getchar(); // Clear newline

        switch (choice) {
            case 1:
                Nhap_Diem(student_id, subject_id, &score);
                break;
            case 2:
                Tim_Sinh_Vien(subject_id);
                break;
            case 3:
                In_Danh_Sach();
                break;
            case 4:
                Them_Sinh_Vien(subject_id);
                break;
            case 5:
                Xoa_Sinh_Vien(subject_id);
                break;
            case 0:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long thu lai!\n");
                system("pause");
        }
    } while (choice != 0);
}

/* NHẬP ĐIỂM CHO SINH VIÊN */
void Nhap_Diem(char* student_id,char* subject_id, float* score){
    ClearScreen();
    printf("=========== NHAP DIEM CHO SINH VIEN ===========\n");
    
    // Nhập MSSV 
    printf("Nhap MSSV: ");
    fgets(student_id, 11, stdin);
    student_id[strcspn(student_id, "\n")] = '\0';
    Chaining* chaining = Search_Student(student_id);
    
    if (chaining == NULL)
    {
        printf("Ma sinh vien khong ton tai.\n");
        system("PAUSE");
        return;
    }

    Student* student = Search_Student(student_id)->Data;
    // Nhập Mã Học Phần
    printf("Nhap Ma Hoc Phan: ");
    fgets(subject_id, 11, stdin);
    subject_id[strcspn(subject_id, "\n")] = '\0';
    Subject* subject = Search_Subject(subject_id)->Data;
    if (subject == NULL)
    {
        printf("Ma Hoc Phan khong ton tai.\n");
        system("PAUSE");
        return;
    }

    // Kiểm tra xem sinh viên đã được nhập điểm môn này chưa 
    int k = 1, i = 0;
    for (; i < student->Number_Of_Subjects;i++){
        if (strcmp(student->Grades[i].Subject_Id, subject_id) == 0){
            printf("Sinh vien da duoc nhap diem mon nay truoc do.\nBan co muon sua diem sinh vien?\n");
            printf("(Nhap Y/y de xac nhan, ky tu bat ky de khong xac nhan)\n");
            getchar();
            char c;
            scanf("%c", &c);
            if (c != 'Y' && c != 'y') return;
            k = 0;
            break;
        }
    }

    // Nhập điểm Kết Thúc Học Phần 
    printf("Nhap diem Ket Thuc Hoc Phan (thang 10): ");
    scanf("%f", score);
    while (*score > 10 || *score < 0){
        printf("Diem Ket Thuc Hoc Phan khong hop le, vui long nhap lai.\n");
        printf("(Nhap -1 de thoat)\n");
        printf("Nhap diem Ket Thuc Hoc Phan (thang 10): ");
        scanf("%f", score);
        if ((float)*score == -1.0) return;
    }

    if (k == 0)
        student->Grades[i].Score = *score; // Ghi đè điểm sinh viên 
    else
        InsertGrades(student_id, subject_id, *score); // Ghi dữ liệu điểm sinh viên
    // Xác nhận dữ liệu
    ClearScreen();
    printf("=========== NHAP DIEM CHO SINH VIEN ===========\n");
    printf("Du lieu duoc ghi thanh cong\n");
    system("PAUSE");
    return;
}
void Tim_Sinh_Vien (char* student_id){
    do{
        ClearScreen();
        printf("=========== TIM KIEM SINH VIEN ===========\n");
        
        // Nhập MSSV 
        printf("Nhap MSSV: ");
        fgets(student_id, 11, stdin);
        student_id[strcspn(student_id, "\n")] = '\0';
        Chaining* chaining = Search_Student(student_id); 
        if (chaining == NULL)
            printf("Ma sinh vien khong ton tai.\n");
        else{
            Student* student = Search_Student(student_id)->Data;
            printf("-------------------------------------------------------\n");
            printf("Thong tin Sinh Vien:\n");
            printf("Ho va Ten: %s\n", student->Student_Name);
            printf("Ngay sinh: %d/%d/%d\n",
                student->Date.tm_mday, student->Date.tm_mon + 1, student->Date.tm_year + 1900);
            printf("Lop: %s\n", student->Class);
            printf("Diem trung binh hoc ky hien tai: %f\n", student->GPA);
            printf("Xep loai: %s\n", student->Rank);
            printf("-------------------------------------------------------\n");
            printf("Diem cac hoc phan cua Sinh Vien:\n");
            for (int i=0; i < student->Number_Of_Subjects; i++)
                printf("%s: %f\n", student->Grades[i].Subject_Id, student->Grades[i].Score);
        }
        printf("Ban co muon tiep tuc tim kiem sinh vien?\n");
        printf("(Nhap Y/y de xac nhan, ky tu bat ky de thoat)\n");
        printf("Lua chon: ");
        getchar();
        char c;
        scanf("%c", &c);
        if (c != 'Y' && c != 'y') return;
    }while(1);
}
void In_Danh_Sach(){
    int choice;
    do {
        ClearScreen();
        printf("=========== DANH SACH SINH VIEN ===========\n");
        printf("1. Sap xep theo MSSV\n");
        printf("2. Sap xep them Ho va Ten\n");
        printf("3. Sap xep theo GPA\n");
        printf("0. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);
        getchar(); // Clear newline

        switch (choice) {
            case 1:
                SortStudentByID();
                break;
            case 2:
                SortStudentByName();
                break;
            case 3:
                SortStudentByGPA();
                break;
            case 0:
                return;
            default:
                printf("Lua chon khong hop le. Vui long thu lai!\n");
        }
        system("PAUSE");
    } while (choice != 0);
}
void Them_Sinh_Vien(char* student_id){
    ClearScreen();
    printf("=========== THEM SINH VIEN ===========\n");
    
    // Nhập MSSV 
    printf("Nhap MSSV: ");
    fgets(student_id, 11, stdin);
    student_id[strcspn(student_id, "\n")] = '\0';
    Chaining* chaining = Search_Student(student_id); 
    if (chaining != NULL)
        printf("Ma sinh vien da ton tai.\n");
    else{
        Student* student = (Student*)malloc(sizeof(Student));
        if (student == NULL) {
            printf("Khong du bo nho de cap phat!\n");
            system("PAUSE");
            return;
        }

        printf("Nhap Ho va Ten sinh vien: ");
        char name[300];
        fgets(name, sizeof(name), stdin);
        name[strcspn(name, "\n")] = '\0';
        trim(name);
        strcpy(student->Student_Name,name);

        printf("Nhap ngay thang nam sinh (dd/mm/yyyy): ");
        if (scanf("%d/%d/%d", &student->Date.tm_mday, &student->Date.tm_mon, &student->Date.tm_year) != 3) {
            printf("Lỗi: Định dạng không hợp lệ! Vui lòng nhập theo dd/mm/yyyy.\n");
            system("PAUSE");
            return; // Kết thúc chương trình với mã lỗi
        }
        while (getchar() != '\n');
        student->Date.tm_mon = student->Date.tm_mon - 1;
        student->Date.tm_year = student->Date.tm_year - 1900;

        printf("Nhap Ma lop Sinh vien: ");
        fgets(student->Class, sizeof(student->Class), stdin);
        student->Class[strcspn(student->Class, "\n")] = '\0';

        strcpy(student->Student_Id, student_id);
        student->GPA = 0.0;
        student->Number_Of_Subjects=0;
        strcpy(student->Rank, "Kem");
        
        Insert_Hash_Data_Student(student);
        if(Search_Student(student_id) != NULL)
            printf("Them sinh vien thanh cong\n");
        else
            printf("Loi, khong them duoc sinh vien\n");
    }
    system("PAUSE");
}
void Xoa_Sinh_Vien(char* student_id){
        ClearScreen();
    printf("=========== XOA SINH VIEN ===========\n");
    
    // Nhập MSSV 
    printf("Nhap MSSV: ");
    fgets(student_id, 11, stdin);
    student_id[strcspn(student_id, "\n")] = '\0';
    Chaining* chaining = Search_Student(student_id); 
    if (chaining == NULL)
        printf("Ma sinh vien khong ton tai.\n");
    else{
        Delete_Student(student_id);
        if(Search_Student(student_id) == NULL)
            printf("Xoa sinh vien thanh cong\n");
        else
            printf("Loi, khong the xoa sinh vien\n");
    }
    system("PAUSE");
}