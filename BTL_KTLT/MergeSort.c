#include "MergeSort.h"
#include <stdlib.h>

// Hàm lấy giá trị của key và so sánh 2 nút
int compareStudent(Student* a, Student* b, const char* key) {
    if (strcmp(key, "Student_Id") == 0) {
        return strcmp(a->Student_Id, b->Student_Id);
    } else if (strcmp(key, "Student_Name") == 0) {
        return strcmp(a->Student_Name, b->Student_Name);
    } else if (strcmp(key, "GPA") == 0) {
        if (a->GPA < b->GPA) return -1;
        if (a->GPA > b->GPA) return 1;
        return 0;
    }
    return 0; // hoặc lỗi
}

// =====================================================
// Sắp xếp các chuỗi theo khóa

// Hàm chia đôi danh sách
void splitList(Chaining* source, Chaining** frontRef, Chaining** backRef) {
    Chaining *slow = source;
    Chaining *fast = source->Next;

    while (fast != NULL) {
        fast = fast->Next;
        if (fast != NULL) {
            slow = slow->Next; // Chạy 1 bước
            fast = fast->Next; // Chạy 2 bước
        }
    }
    // slow sẽ nằm ở giữa danh sách, fast nằm ở cuốicuối
    *frontRef = source;
    *backRef = slow->Next;
    slow->Next = NULL;
}

// Hàm gộp 2 danh sách đã sắp xếp
Chaining* sortedMerge(Chaining* a, Chaining* b, const char* key) {
    Chaining* result = NULL;

    if (a == NULL)
        return b;
    else if (b == NULL)
        return a;
    // So sánh 2 sinh viên dựa trên khóa
    if (compareStudent(a->Data, b->Data, key) <= 0) {
        result = a;
        result->Next = sortedMerge(a->Next, b, key);
    } else {
        result = b;
        result->Next = sortedMerge(a, b->Next, key);
    }

    return result;
}

// Merge Sort chính
void mergeSort(Chaining** headRef, const char* key) {
    Chaining* head = *headRef; // headRef con trỏ lưu trữ đầu danh sách
    Chaining* a;
    Chaining* b;

    if ((head == NULL) || (head->Next == NULL)) {
        return;
    }

    splitList(head, &a, &b);
    mergeSort(&a, key);
    mergeSort(&b, key);
    *headRef = sortedMerge(a, b, key); // Cập nhật lại đầu danh sách
}

