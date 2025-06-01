#include "Hash.h"
#include <ctype.h>
#include <string.h>
#define TABLE_SIZE 10

unsigned int hash(char *str) {
    unsigned long long hash = 0;
    while (*str) {
        hash = (hash << 5) + *str++;
    }
    return hash % TABLE_SIZE;
}
// Hàm chuyển về các ký tự thường
void tolowerCase(char *str) {
    for (; *str; ++str) *str = tolower(*str);
}

// Hàm trim chuẩn hóa chuỗi (xóa khoảng trắng đầu/cuối)
void trim(char *str) {
    char *start = str;
    while (isspace((unsigned char)*start)) start++;
    if (start != str) memmove(str, start, strlen(start) + 1);

    char *end = str + strlen(str) - 1;
    while (end >= str && isspace((unsigned char)*end)) end--;
    *(end + 1) = '\0';
}