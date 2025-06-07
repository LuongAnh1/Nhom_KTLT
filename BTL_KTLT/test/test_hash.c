#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Hash.h"  // Gồm các hàm: hash, tolowerCase, trim

int main() {
    char test1[] = "   nguyen    van     A    ";
    char test2[] = " LE   THI   B   ";
    char test3[] = "  tran QUOC   DAt ";
    char temp[100];

    // Test ham trim (chuan hoa ten)
    printf("=== Test ham trim (chuan hoa ten) ===\n");

    strcpy(temp, test1);
    trim(temp);
    printf("Ten goc: '%s'\n", test1);
    printf("Sau khi chuan hoa: '%s'\n\n", temp);

    strcpy(temp, test2);
    trim(temp);
    printf("Ten goc: '%s'\n", test2);
    printf("Sau khi chuan hoa: '%s'\n\n", temp);

    strcpy(temp, test3);
    trim(temp);
    printf("Ten goc: '%s'\n", test3);
    printf("Sau khi chuan hoa: '%s'\n\n", temp);

    // Test ham hash
    printf("=== Test ham hash ===\n");
    printf("Hash('%s') = %u\n", temp, hash(temp));

    strcpy(temp, "Nguyen Van B");
    printf("Hash('%s') = %u\n", temp, hash(temp));

    strcpy(temp, "Nguyen Van C");
    printf("Hash('%s') = %u\n", temp, hash(temp));
    system("PAUSE");
    return 0;
}
