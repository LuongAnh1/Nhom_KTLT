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
// Chuyển tất cả thành chữ thường
void tolowerCase(char *str) {
    for (; *str; ++str) *str = tolower((unsigned char)*str);
}

// Hàm chuẩn hóa chuỗi: xóa khoảng trắng đầu/cuối, gộp khoảng trắng giữa, viết hoa chữ đầu
void trim(char *str) {
    // Bỏ khoảng trắng đầu
    char *start = str;
    while (isspace((unsigned char)*start)) start++;
    if (start != str) memmove(str, start, strlen(start) + 1);

    // Bỏ khoảng trắng cuối
    char *end = str + strlen(str) - 1;
    while (end >= str && isspace((unsigned char)*end)) end--;
    *(end + 1) = '\0';

    // Gộp khoảng trắng giữa các từ (loại bỏ khoảng trắng thừa)
    char *src = str, *dst = str;
    int space = 0;
    while (*src) {
        if (isspace((unsigned char)*src)) {
            if (!space) {
                *dst++ = ' ';
                space = 1;
            }
        } else {
            *dst++ = *src;
            space = 0;
        }
        src++;
    }
    *dst = '\0';

    // Chuyển về chữ thường
    tolowerCase(str);

    // Viết hoa chữ cái đầu mỗi từ
    int newWord = 1;
    for (char *p = str; *p; ++p) {
        if (isspace((unsigned char)*p)) {
            newWord = 1;
        } else if (newWord) {
            *p = toupper((unsigned char)*p);
            newWord = 0;
        }
    }
}