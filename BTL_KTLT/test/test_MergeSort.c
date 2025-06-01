#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Chaining.h"
#include "MergeSort.h"

int test_compareStudent() {
    Student a = {"SV001", "An", {0}, "CTK42", 0, {}, 3.0, ""};
    Student b = {"SV002", "Binh", {0}, "CTK42", 0, {}, 4.0, ""};
    return compareStudent(&a, &b, "GPA") < 0;
}

int test_splitList() {
    Student a = {"SV001", "An"}, b = {"SV002", "Binh"}, c = {"SV003", "Cuong"};
    Chaining *head = NULL;
    head = Insert(head, &a, a.Student_Id);
    head = Insert(head, &b, b.Student_Id);
    head = Insert(head, &c, c.Student_Id);

    Chaining *front = NULL, *back = NULL;
    splitList(head, &front, &back);
    return front && back;
}

int test_sortedMerge() {
    Student a = {"SV001", "An", {0}, "", 0, {}, 1.5, ""};
    Student b = {"SV002", "Binh", {0}, "", 0, {}, 3.0, ""};
    Chaining* l1 = Insert(NULL, &a, a.Student_Id);
    Chaining* l2 = Insert(NULL, &b, b.Student_Id);
    Chaining* merged = sortedMerge(l1, l2, "GPA");
    return merged && ((Student*)merged->Data)->GPA == 1.5;
}

int test_mergeSort() {
    Student s1 = {"SV003", "Cuong", {0}, "", 0, {}, 2.0, ""};
    Student s2 = {"SV001", "An", {0}, "", 0, {}, 3.5, ""};
    Chaining* list = NULL;
    list = Insert(list, &s1, s1.Student_Id);
    list = Insert(list, &s2, s2.Student_Id);
    mergeSort(&list, "GPA");
    return ((Student*)list->Data)->GPA == 2.0;
}

void print_result(const char* func, int result) {
    printf("Ham %s trong MergeSort.c: %s\n", func, result ? "DUNG" : "SAI");
}

int main() {
    print_result("compareStudent", test_compareStudent());
    print_result("splitList", test_splitList());
    print_result("sortedMerge", test_sortedMerge());
    print_result("mergeSort", test_mergeSort());
    system("PAUSE");
    return 0;
}
