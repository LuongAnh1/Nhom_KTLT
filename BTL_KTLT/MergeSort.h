#ifndef MERGESORT_H
#define MERGESORT_H
#include "Data.h"

// Hàm lấy giá trị của key và so sánh 2 nút
int compareStudent(Student* a, Student* b, const char* key);
// Hàm chia đôi danh sách
void splitList(Chaining* source, Chaining** frontRef, Chaining** backRef);
// Hàm gộp 2 danh sách đã sắp xếp
Chaining* sortedMerge(Chaining* a, Chaining* b, const char* key);
// Merge Sort chính
void mergeSort(Chaining** headRef, const char* key);

#endif
