#ifndef MERGESORT_H
#define MERGESORT_H
#include "Data.h"

// Hàm sắp xếp chuỗi
// Hàm chia đôi
void Split(Chaining* source, Chaining** frontRef, Chaining** backRef);
// Hàm trộn
void MergeSort(Chaining* left, Chaining* right);

// Hàm in ra kết quả khi trộn các danh sách

// Cấu trúc cho phần tử heap
typedef struct HeapNode{
    Chaining* node; // Con trỏ tới node hiện tại trong mỗi danh sách
    int listIndex;  // Chỉ số của danh sách
};
typedef struct HeapNode HeapNode;
// Hàm K-Way Merge sử dụng Min-Heap
Chaining* KWayMerge(Chaining** lists, int k);

// Hàm tạo Min-Heap từ mảng HeapNode
void MinHeapify(HeapNode heap[], int size, int i);

// Hàm lấy phần tử nhỏ nhất từ heap
HeapNode ExtractMin(HeapNode heap[], int* size);

// Hàm chèn phần tử vào heap
void InsertHeap(HeapNode heap[], int* size, HeapNode value);


#endif
