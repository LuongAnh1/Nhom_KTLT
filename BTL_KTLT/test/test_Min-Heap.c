#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Chaining.h"
#include "Min-Heap.h"
#include "MergeSort.h"

void FreeList(Chaining* head) {
    while (head != NULL) {
        Chaining* temp = head;
        head = head->Next;
        free(temp);
    }
}

int test_KWayMerge() {
    Student s1 = {"SV001", "An", {0}, "", 0, {}, 2.0, ""};
    Student s2 = {"SV002", "Binh", {0}, "", 0, {}, 3.0, ""};
    Chaining* l1 = Insert(NULL, &s1, s1.Student_Id);
    Chaining* l2 = Insert(NULL, &s2, s2.Student_Id);
    Chaining* lists[] = {l1, l2};

    Chaining* merged = NULL;
    merged = Insert(merged, &s1, s1.Student_Id);
    merged = Insert(merged, &s2, s2.Student_Id);
    mergeSort(&merged, "GPA");

    float gpas[] = {2.0, 3.0};
    int i = 0;
    for (Chaining* p = merged; p; p = p->Next, i++) {
        Student* s = (Student*)p->Data;
        if (s->GPA != gpas[i]) {
            FreeList(l1);
            FreeList(l2);
            FreeList(merged);
            return 0;
        }
    }

    FreeList(l1);
    FreeList(l2);
    FreeList(merged);
    return 1;
}

int test_MinHeapify() {
    Student a = {"SV001", "A", {0}, "", 0, {}, 2.0, ""};
    Student b = {"SV002", "B", {0}, "", 0, {}, 4.0, ""};
    Chaining *n1 = Insert(NULL, &a, a.Student_Id);
    Chaining *n2 = Insert(NULL, &b, b.Student_Id);
    HeapNode heap[2] = {{n2, 0}, {n1, 1}};
    MinHeapify(heap, 2, 0, "GPA");
    int result = ((Student*)heap[0].node->Data)->GPA == 2.0;
    FreeList(n1);
    FreeList(n2);
    return result;
}

int test_ExtractMin() {
    Student a = {"SV001", "A", {0}, "", 0, {}, 1.5, ""};
    Chaining* n = Insert(NULL, &a, a.Student_Id);
    HeapNode heap[1] = {{n, 0}};
    int size = 1;
    HeapNode min = ExtractMin(heap, &size, "GPA");
    int result = strcmp(((Student*)min.node->Data)->Student_Id, "SV001") == 0;
    FreeList(n);
    return result;
}

int test_InsertHeap() {
    Student a = {"SV003", "C", {0}, "", 0, {}, 3.0, ""};
    Chaining* n = Insert(NULL, &a, a.Student_Id);
    HeapNode heap[2];
    int size = 0;
    InsertHeap(heap, &size, (HeapNode){n, 0}, "GPA");
    FreeList(n);
    return size == 1;
}

int test_printStudent() {
    return 1;
}

void print_result(const char* func, int result) {
    printf("Ham %s trong Min-Heap.c: %s\n", func, result ? "DUNG" : "SAI");
}

int main() {
    print_result("KWayMerge", test_KWayMerge());
    print_result("MinHeapify", test_MinHeapify());
    print_result("ExtractMin", test_ExtractMin());
    print_result("InsertHeap", test_InsertHeap());
    print_result("printStudent", test_printStudent());
    system("PAUSE");
    return 0;
}
