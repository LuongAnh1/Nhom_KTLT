#include "Subject.h"
#include "Hash.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "Chaining.h"

// Thêm môn học vào bảng băm
void Insert_Hash_Data_Subject (Subject *subject) {
    int index = hash(&(subject->Subject_Id)); // Tính toán chỉ số băm
    Table_Subjects[index] = Insert(Table_Subjects[index], subject, subject->Subject_Id); // Thêm môn học vào danh sách liên kết
}

// Đọc dữ liệu từ tệp và thêm vào bảng băm
void Load_Data_Subject(const char *filename) {
    FILE *f = fopen(filename, "r"); // Tạo con trỏ tệp
    if (f == NULL) { // Kiểm tra xem tệp có mở thành công không
        printf("Mo file loi\n");
        return;
    }
    char line[200]; // Biến tạm để đọc từng dòng
    while (fgets(line, sizeof(line), f)) { // Đọc từng dòng
        Subject *subject = (Subject *)malloc(sizeof(Subject));
        sscanf(line, "%[^,],%[^,],%d", subject->Subject_Id, subject->Subject_Name, &subject->Credits);
        // Thêm vào bẳng băm
        Insert_Hash_Data_Subject(subject); // Thêm môn học vào bảng băm
    }
    fclose(f); // Đóng tệp
}

// Tìm kiếm môn học trong bảng băm
Chaining* Search_Subject (char *subject_id) {
    int index = hash(subject_id); // Tính toán chỉ số băm
    return Search(Table_Subjects[index], subject_id); // Tìm kiếm môn học
}

// Ghi lại dữ liệu vào tệp
void Write_Subject_Data(const char *filename) {
    FILE *f = fopen(filename, "w"); // Tạo con trỏ tệp
    if (f == NULL) { // Kiểm tra xem tệp có mở thành công không
        printf("Khong the mo file\n");
        return;
    }
    for (int i = 0; i < MAX_TABLE_SUBJECTS; i++) { // Duyệt qua bảng băm
        Chaining *temp = Table_Subjects[i]; // Con trỏ bắt đầu từ đầu danh sách
        while (temp != NULL) {
            Subject *subject = (Subject *)temp->Data; // Lấy dữ liệu môn học
            // Ghi dữ liệu vào tệp
            fprintf(f, "%s,%s,%d\n", subject->Subject_Id, subject->Subject_Name, subject->Credits); // Ghi dữ liệu vào tệp
            temp = temp->Next; // Chuyển đến môn học tiếp theo
        }
    }
    fclose(f); // Đóng tệp
}