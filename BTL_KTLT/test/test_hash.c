#include <stdio.h>
#include <stdlib.h>
#include "Hash.h"

int main() {
    char *key1 = "hoa";
    char *key2 = "an";
    char *key3 = "binh";
    char *key4 = "nam";

    printf("Input: Tinh gia tri bam cho cac khoa: 'hoa', 'an', 'binh', 'nam'\n");

    printf("Output: Gia tri bam cua '%s' la: %u\n", key1, hash(key1));
    printf("Output: Gia tri bam cua '%s' la: %u\n", key2, hash(key2));
    printf("Output: Gia tri bam cua '%s' la: %u\n", key3, hash(key3));
    printf("Output: Gia tri bam cua '%s' la: %u\n", key4, hash(key4));

    system("PAUSE");
    return 0;
}