#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Chaining.h"
#include "MergeSort.h"

void freeList(Chaining* head) {
    while (head) {
        Chaining* temp = head;
        head = head->Next;
        free(temp);
    }
}

int test_compareStudent() {
    Student a = {"SV001", "An", {0}, "", 0, {}, 8.5, ""};
    Student b = {"SV002", "Binh", {0}, "", 0, {}, 7.5, ""};
    return compareStudent(&a, &b, "GPA") > 0;
}

int test_splitList() {
    Student s1 = {"SV001"}, s2 = {"SV002"}, s3 = {"SV003"};
    Chaining* list = NULL;
    list = Insert(list, &s1, s1.Student_Id);
    list = Insert(list, &s2, s2.Student_Id);
    list = Insert(list, &s3, s3.Student_Id);
    Chaining *front = NULL, *back = NULL;
    splitList(list, &front, &back);
    int result = front && back;
    freeList(front);
    freeList(back);
    return result;
}

int test_sortedMerge() {
    Student s1 = {"SV001", "An", {0}, "", 0, {}, 6.0, ""};
    Student s2 = {"SV002", "Binh", {0}, "", 0, {}, 7.0, ""};
    Chaining* l1 = Insert(NULL, &s1, s1.Student_Id);
    Chaining* l2 = Insert(NULL, &s2, s2.Student_Id);
    Chaining* result = sortedMerge(l1, l2, "GPA");
    int ok = ((Student*)result->Data)->GPA == 6.0;
    freeList(result);
    return ok;
}

int test_mergeSort() {
    Student s1 = {"SV001", "An", {0}, "", 0, {}, 7.0, ""};
    Student s2 = {"SV002", "Binh", {0}, "", 0, {}, 5.0, ""};
    Chaining* list = NULL;
    list = Insert(list, &s1, s1.Student_Id);
    list = Insert(list, &s2, s2.Student_Id);
    mergeSort(&list, "GPA");
    int result = ((Student*)list->Data)->GPA == 5.0;
    freeList(list);
    return result;
}

void print_result(const char* name, int result) {
    printf("Hàm %s trong MergeSort.c: %s\n", name, result ? "ĐÚNG" : "SAI");
}

int main() {
    print_result("compareStudent", test_compareStudent());
    print_result("splitList", test_splitList());
    print_result("sortedMerge", test_sortedMerge());
    print_result("mergeSort", test_mergeSort());
    return 0;
}
