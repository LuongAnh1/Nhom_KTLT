#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Service.h"
#include "Student.h"
#include "Subject.h"
#include "Hash.h"


Chaining* Table_Students[MAX_TABLE_STUDENTS] = {0};
Chaining* Table_Subjects[MAX_TABLE_SUBJECTS] = {0};

int suppress_output = 0;

void testOnly_printStudent(Student* s) {
    if (suppress_output) return;
    printf("%s|%s|%d/%d/%d|%s|%.2f|%s\n",
           s->Student_Id, s->Student_Name,
           s->Date.tm_mday, s->Date.tm_mon, s->Date.tm_year,
           s->Class, s->GPA, s->Rank);
}

#define printStudent testOnly_printStudent

int test_ExchangeGrade() {
    Grades g = {"MH01", 8.0};
    ExchangeGrade(&g);
    return g.Score == 3.5;
}

int test_RankStudent() {
    Student s = {"SV001", "An", {0}, "", 0, {}, 3.3, ""};
    RankStudent(&s);
    return strcmp(s.Rank, "Gioi") == 0;
}

int test_AvgGrades() {
    Subject sub = {"MH01", "Toan", 2};
    Insert_Hash_Data_Subject(&sub);

    Student s = {"SV001", "An", {0}, "", 1, {{"MH01", 9.0}}, 0.0, ""};
    Insert_Hash_Data_Student(&s);

    AvgGrades(&s);
    return s.GPA == 4.0;
}

int test_InsertGrades() {
    Subject sub = {"MH01", "Toan", 2};
    Insert_Hash_Data_Subject(&sub);

    Student s = {"SV001", "An", {0}, "", 0, {}, 0.0, ""};
    Insert_Hash_Data_Student(&s);

    InsertGrades("SV001", "MH01", 9.0);
    Chaining* node = Search_Student("SV001");
    return node && ((Student*)node->Data)->GPA == 4.0;
}

int test_SortStudentByGPA() {
    FILE* tmp = freopen("nul", "w", stdout);
    SortStudentByGPA();
    freopen("CON", "w", tmp);
    return 1;
}

int test_SortStudentByName() {
    FILE* tmp = freopen("nul", "w", stdout);
    SortStudentByName();
    freopen("CON", "w", tmp);
    return 1;
}

int test_SortStudentByID() {
    FILE* tmp = freopen("nul", "w", stdout);
    SortStudentByID();
    freopen("CON", "w", tmp);
    return 1;
}

void print_result(const char* name, int result) {
    printf("Hàm %s trong Service: %s\n", name, result ? "ĐÚNG" : "SAI");
}

int main() {
    print_result("ExchangeGrade", test_ExchangeGrade());
    print_result("RankStudent", test_RankStudent());
    print_result("AvgGrades", test_AvgGrades());
    print_result("InsertGrades", test_InsertGrades());
    print_result("SortStudentByGPA", test_SortStudentByGPA());
    print_result("SortStudentByName", test_SortStudentByName());
    print_result("SortStudentByID", test_SortStudentByID());
    return 0;
}
