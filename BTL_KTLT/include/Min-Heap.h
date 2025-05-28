#ifndef MIN_HEAP_H
#define MIN_HEAP_H
#include "Data.h"

// Hàm in ra thông tin sinh viên
void printStudent(Student *student);
// Hàm K-Way Merge sử dụng Min-Heap (chính)
void KWayMerge(Chaining** lists, int k, const char *key);

// Hàm tạo Min-Heap từ mảng HeapNode
void MinHeapify(HeapNode heap[], int size, int i, const char *key);

// Hàm lấy phần tử nhỏ nhất từ heap
HeapNode ExtractMin(HeapNode heap[], int* size, const char *key);

// Hàm chèn phần tử vào heap
void InsertHeap(HeapNode heap[], int* size, HeapNode value,const char *key);

#endif