#include "Min-Heap.h"
#include "MergeSort.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

// So sánh hai node 
int Compare(Chaining* a, Chaining* b, const char *key) {
    // Thay đổi theo kiểu dữ liệu thực tế của bạn
    return compareStudent(a->Data,b->Data,key);
}
// Hàm sắp xếp lại các phần tử sao cho đúng với cây Min-Heap
void MinHeapify(HeapNode heap[], int size, int i, const char *key) {
    // i là nút cần điều chỉnh
    // Gán phần tử nhỏ nhất là nút cha  
    int smallest = i;
    int left = 2 * i + 1; // Nút con trái
    int right = 2 * i + 2; // Nút con phải

    // Tìm phần tử nhỏ nhất trong 3 nút cha, cont trái, con phải
    // Nếu tồn tại nút con trái và nút con trái > nút cha (vi phạm Min-Heap)
    if (left < size && Compare(heap[left].node, heap[smallest].node,key) < 0)
        smallest = left; // Phần tử nhơ phần bằng con trái
    // Nếu tồn tại nút con phải và nút con phải > nút cha (vi phạm Min-Heap)
    if (right < size && Compare(heap[right].node, heap[smallest].node,key) < 0)
        smallest = right; // Gán lại

    if (smallest != i) // Nếu như nút nhỏ nhất không phải cha 
    {
        // Đổi chỗ nút cha với nút nhỏ nhất 
        HeapNode temp = heap[i]; 
        heap[i] = heap[smallest];
        heap[smallest] = temp;
        // Sắp xếp lại đối với nút cha vừa được đưa xuống 
        MinHeapify(heap, size, smallest,key);
    }
}

// Ham lấy ra phần tử nhỏ nhất của Min-Heap
HeapNode ExtractMin(HeapNode heap[], int* size, const char *key) {
    HeapNode min = heap[0];
    heap[0] = heap[*size - 1]; // Đưa phần tử cuối lên đầu 
    (*size)--; // Giảm kích thước mảng
    MinHeapify(heap, *size, 0,key); // Sắp xếp lại mảng Min-Heap
    return min; // Trả về phần tử nhỏ nhất 
}

// Hàm thêm phần tử vào Min-Heap 
void InsertHeap(HeapNode heap[], int* size, HeapNode value,const char *key) {
    int i = (*size)++; // Gán i = phần tử cuối cùng, sau đó tăng kích thước mảng 
    heap[i] = value; // Phần tử cuối cùng của mảng bằng giá trị cần thêm 
    // Đưa nút vừa thêm về vị trí của nó (Đưa dần lên trên)
    while (i != 0 && Compare(heap[i].node, heap[(i - 1) / 2].node,key) < 0) {
        HeapNode temp = heap[i];
        heap[i] = heap[(i - 1) / 2];
        heap[(i - 1) / 2] = temp;
        i = (i - 1) / 2; // Gán i về vị trí nút cần thêm sau khi thay đổi 
    }
}

// Hàm in ra thông tin sinh viên
void printStudent(Student *student){
    printf("%s|%s|%d/%d/%d|%s|%f|%s\n",
            (*student).Student_Id,
            (*student).Student_Name,
            (*student).Date.tm_mday,
            (*student).Date.tm_mon + 1,
            (*student).Date.tm_year + 1900,
            (*student).Class,
            (*student).GPA,
            (*student).Rank);
}
// -------------------------------------------------------
// Hàm chính
// lists = *Table_Students[MAX_TABLE_STUDENTS];
void KWayMerge(Chaining** lists, int k, const char *key) {
    if (k == 0) return; // Kiểm tra số phần tử cần sắp xếp
    HeapNode* heap = (HeapNode*)malloc(sizeof(HeapNode) * k); 
    // Cấp bộ nhớ k phần tử liên tiếp cho mảng lưu các phần tử Min-Heap 
    int heapSize = 0; // Khơi tạo kích cỡ của mảng Heap = 0

    // Khởi tạo heap với node đầu tiên của mỗi danh sách
    for (int i = 0; i < k; i++) {
        if (lists[i] != NULL) // Nếu như con trỏ trỏ vào sanh sách khác NULL 
        {
            heap[heapSize].node = lists[i]; // Gán data phần tử Heap thứ i = con trỏ trỏ vào danh sách
            //heap[heapSize].listIndex = i; // Gán chỉ số của phần tử (thuộc danh sách thứ mấy)
            heapSize++; // Tăng giá trị kích cỡ mảng Heap
        }
    }

    // Xây dựng min-heap
    for (int i = heapSize / 2 - 1; i >= 0; i--) {
        // Sắp xếp lại từ vị trí heapSize/2 - 1 (tức nút phải nhất và dưới nhất có con)
        MinHeapify(heap, heapSize, i,key); 
        // Hàm điều chỉnh lại vị trí phần tử sao cho tuần theo đúng cây nhị phân Min-HeapHeap
    }

    while (heapSize > 0) {
        // Hàm lấy ra phần tử bé nhất của cây Min-Heap
        HeapNode minNode = ExtractMin(heap, &heapSize,key); 
         // In ra dữ liệu của node nhỏ nhất
        printStudent((Student*)minNode.node->Data);  

        // Lấy node tiếp theo từ danh sách vừa lấy node nhỏ nhất
        if (minNode.node->Next) {
            HeapNode newNode;
            newNode.node = minNode.node->Next;
            //newNode.listIndex = minNode.listIndex;
            InsertHeap(heap, &heapSize, newNode,key); // Chèn phần tử mới vào Min-HeapHeap
        }
    }
    free(heap);
}