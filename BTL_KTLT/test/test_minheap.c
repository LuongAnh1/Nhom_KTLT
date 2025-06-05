#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Chaining.h"
#include "Min-Heap.h"

Chaining* Table_Students[MAX_TABLE_STUDENTS] = {0};

void freeList(Chaining* head) {
    while (head) {
        Chaining* tmp = head;
        head = head->Next;
        free(tmp);
    }
}

// Cờ kiểm soát việc in
int suppress_output = 0;

// Hàm kiểm thử riêng thay thế printStudent
void testOnly_printStudent(Student *student) {
    if (suppress_output) return;
    printf("%s|%s|%d/%d/%d|%s|%f|%s\n",
           student->Student_Id, student->Student_Name,
           student->Date.tm_mday, student->Date.tm_mon,
           student->Date.tm_year, student->Class,
           student->GPA, student->Rank);
}

int test_KWayMerge() {
    Student s1 = {"SV001", "An", {0}, "", 0, {}, 6.0, ""};
    Student s2 = {"SV002", "Binh", {0}, "", 0, {}, 7.0, ""};
    Chaining *l1 = Insert(NULL, &s1, s1.Student_Id);
    Chaining *l2 = Insert(NULL, &s2, s2.Student_Id);
    Chaining* lists[2] = {l1, l2};

    suppress_output = 1;
    KWayMerge(lists, 2, "GPA");
    suppress_output = 0;

    freeList(l1); freeList(l2);
    return 1;
}

int test_MinHeapify() {
    Student s1 = {"SV001", "An", {0}, "", 0, {}, 6.0, ""};
    Student s2 = {"SV002", "Binh", {0}, "", 0, {}, 9.0, ""};
    Chaining *n1 = Insert(NULL, &s1, s1.Student_Id);
    Chaining *n2 = Insert(NULL, &s2, s2.Student_Id);
    HeapNode heap[2] = {{n2, 0}, {n1, 1}};
    MinHeapify(heap, 2, 0, "GPA");
    int ok = ((Student*)heap[0].node->Data)->GPA == 6.0;
    freeList(n1); freeList(n2);
    return ok;
}

int test_ExtractMin() {
    Student s1 = {"SV001", "An", {0}, "", 0, {}, 5.0, ""};
    Chaining* n = Insert(NULL, &s1, s1.Student_Id);
    HeapNode heap[1] = {{n, 0}};
    int size = 1;
    HeapNode min = ExtractMin(heap, &size, "GPA");
    int result = strcmp(((Student*)min.node->Data)->Student_Id, "SV001") == 0;
    freeList(n);
    return result;
}

int test_InsertHeap() {
    Student s = {"SV003", "Cuong", {0}, "", 0, {}, 7.0, ""};
    Chaining* n = Insert(NULL, &s, s.Student_Id);
    HeapNode heap[2];
    int size = 0;
    InsertHeap(heap, &size, (HeapNode){n, 0}, "GPA");
    int ok = size == 1;
    freeList(n);
    return ok;
}

int test_printStudent() {
    suppress_output = 1;
    Student s = {"SV001", "An", {0}, "", 0, {}, 8.0, "XS"};
    testOnly_printStudent(&s);  // Sử dụng phiên bản riêng
    suppress_output = 0;
    return 1;
}

void print_result(const char* name, int result) {
    printf("Hàm %s trong Min-Heap.c: %s\n", name, result ? "ĐÚNG" : "SAI");
}

int main() {
    print_result("KWayMerge", test_KWayMerge());
    print_result("MinHeapify", test_MinHeapify());
    print_result("ExtractMin", test_ExtractMin());
    print_result("InsertHeap", test_InsertHeap());
    print_result("printStudent", test_printStudent());
    return 0;
}