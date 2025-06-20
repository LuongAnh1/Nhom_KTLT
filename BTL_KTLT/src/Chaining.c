#include "Chaining.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int CompareString (void* str1, void* str2) { // Hàm so sánh chuỗi
    return strcmp((char*)str1, (char*)str2); // So sánh hai chuỗi
}
Chaining* CreatNode(void* Data, void* Key){ // Tham số nhận vào là dữ liệu nút và khóa
    // Tạo một nút mới với dữ liệu và khóa
    Chaining* newNode = (Chaining*)malloc(sizeof(Chaining)); // Cấp phát bộ nhớ cho nút mới
    if (newNode == NULL) { // Kiểm tra xem việc cấp phát có thành công không
        printf("Cung cap bo nho loi\n");
        return NULL;
    }
    newNode->Data = Data; // Gán dữ liệu cho nút mới
    newNode->Next = NULL; // Khởi tạo con trỏ tiếp theo là NULL
    newNode->Key = Key; // Gán khóa cho nút mới
    return newNode; // Trả về con trỏ tới nút mới
}
Chaining* Insert(Chaining* head, void* Data, void* Key) {
    Chaining* newNode = CreatNode(Data, Key);
    if (!newNode) return head;

    // Nếu danh sách rỗng hoặc node mới cần chèn lên đầu
    if (head == NULL || CompareString(Key, head->Key) < 0) {
        newNode->Next = head;
        return newNode;
    }

    Chaining* cur = head;
    // Tìm vị trí chèn
    while (cur->Next != NULL && CompareString(Key, cur->Next->Key) >= 0) {
        cur = cur->Next;
    }

    newNode->Next = cur->Next;
    cur->Next = newNode;
    return head;
}

Chaining* Search(Chaining* head, void* Key){
    Chaining* temp = head; // Con trỏ tạm để duyệt danh sách
    while (temp != NULL) { // Duyệt danh sách
        if (CompareString(temp->Key, Key) == 0) { // Nếu tìm thấy dữ liệu
            return temp; // Trả về con trỏ tới nút tìm thấy
        }
        temp = temp->Next; // Chuyển đến nút tiếp theo
    }
    return NULL; // Trả về NULL nếu không tìm thấy
}
Chaining* Delete(Chaining* head, void* Key){
    Chaining* temp = Search(head, Key); // Tìm nút cần xóa
    if (temp == NULL){
        // Nếu không tìm thấy nút cần xóa
        printf("Khong tim thay du lieu de xoa\n");
        return head;
    } 
    else{
        Chaining* prev = head; // Con trỏ tạm để duyệt danh sách
        if (prev == temp) {
            head = temp->Next; // Nếu nút cần xóa là đầu danh sách
            free(temp); // Giải phóng bộ nhớ của nút cần xóa
            return head;
        }
        while (prev->Next != temp) { // Duyệt danh sách để tìm nút trước nút cần xóa
            prev = prev->Next; // Chuyển đến nút tiếp theo
        }
        prev->Next = temp->Next; // Gán con trỏ tiếp theo của nút trước nút cần xóa
        free(temp); // Giải phóng bộ nhớ của nút cần xóa
        return head; // Trả về đầu danh sách đã cập nhật
    }
}