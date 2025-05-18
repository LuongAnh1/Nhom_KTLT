#include "Subject.h"
#include "Hash.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

// Thêm môn học vào bảng băm
void Insert_Hash_Data_Subject (Subject *subject) {
    int index = hash(&(subject->Subject_Id)); // Tính toán chỉ số băm
    if (Table_Subjects[index] == NULL) { // Nếu vị trí trống, thêm vào
        Table_Subjects[index] = subject;
    } else {
        Subject *temp = Table_Subjects[index]; 
        while (temp->Next != NULL) { // Xử lý xung đột
            temp = temp->Next;
        }
        temp->Next = subject;
    }
}

// Đọc dữ liệu từ tệp và thêm vào bảng băm
void Load_Data_Subject() {
    FILE *f = fopen("Subject.txt", "r"); // Tạo con trỏ tệp
    if (f == NULL) { // Kiểm tra xem tệp có mở thành công không
        printf("Error opening file\n");
        return;
    }
    char line[200]; // Biến tạm để đọc từng dòng
    while (fgets(line, sizeof(line), f)) { // Đọc từng dòng
        Subject *subject = (Subject *)malloc(sizeof(Subject));
        sscanf(line, "%[^,],%[^,],%d", subject->Subject_Id, subject->Subject_Name, &subject->Credits);
        subject->Next = NULL;

        // Thêm vào bẳng băm
        Insert_Hash_Data_Subject(subject);
    }
    fclose(f); // Đóng tệp
}

// Tìm kiếm môn học trong bảng băm
Subject* Search_Subject (char *subject_id) {
    int index = hash(subject_id); // Tính toán chỉ số băm
    Subject *temp = Table_Subjects[index]; // Con trỏ bắt đầu từ đầu danh sáchsách
    while (temp != NULL) {
        if (strcmp(&(temp->Subject_Id), subject_id) == 0)  // Tìm thấy môn học
            break; // dừng vòng lặplặp
        temp = temp->Next; // Chuyển đến môn học tiếp theo
    }
    return temp; // Trả về con trỏ trỏ tới bộ nhớ môn học hoặc NULL nếu không tìm thấy
}

// Ghi lại dữ liệu vào tệp
void Write_Subject_Data() {
    FILE *f = fopen("Subject.txt", "w"); // Tạo con trỏ tệp
    if (f == NULL) { // Kiểm tra xem tệp có mở thành công không
        printf("Error opening file\n");
        return;
    }
    for (int i = 0; i < MAX_TABLE_SUBJECTS; i++) { // Duyệt qua bảng băm
        Subject *temp = Table_Subjects[i]; // Con trỏ bắt đầu từ đầu danh sách
        while (temp != NULL) {
            fprintf(f, "%s,%s,%d\n", temp->Subject_Id, temp->Subject_Name, temp->Credits); // Ghi dữ liệu vào tệp
            temp = temp->Next; // Chuyển đến môn học tiếp theo
        }
    }
    fclose(f); // Đóng tệp
}