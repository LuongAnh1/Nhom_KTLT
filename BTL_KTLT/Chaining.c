#include "Chaining.h"

Chaining* CreatNode(void* Data, void* Key){
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
void Insert(Chaining* head, void* Data, void* Key){
    Chaining* newNode = CreatNode(Data, Key); // Tạo nút mới
    if (head == NULL) { // Nếu danh sách rỗng, gán nút mới làm đầu danh sách
        head = newNode; // Gán nút mới làm đầu danh sách
        return;
    }
    Chaining* temp = head; // Con trỏ tạm để duyệt danh sách
    while (temp->Next != NULL) { // Duyệt đến cuối danh sách
        temp = temp->Next;
    }
    temp->Next = newNode; // Gán nút mới vào cuối danh sách
}
Chaining* Search(Chaining* head, void* Key){
    Chaining* temp = head; // Con trỏ tạm để duyệt danh sách
    while (temp != NULL) { // Duyệt danh sách
        if (temp->Key == Key) { // Nếu tìm thấy dữ liệu
            return temp; // Trả về con trỏ tới nút tìm thấy
        }
        temp = temp->Next; // Chuyển đến nút tiếp theo
    }
    return NULL; // Trả về NULL nếu không tìm thấy
}
void Delete(Chaining* head, void* Key){
    Chaining* temp = Search(head, Key); // Tìm nút cần xóa
    if (temp == NULL) // Nếu không tìm thấy nút cần xóa
        printf("Khong tim thay du lieu de xoa\n");
    else
        free(temp); // Giải phóng bộ nhớ của nút cần xóa
}