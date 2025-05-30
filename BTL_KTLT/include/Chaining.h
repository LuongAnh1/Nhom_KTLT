#ifndef CHAINING_H
#define CHAINING_H
#include "Data.h"

int CompareString (void* str1, void* str2);
Chaining* CreatNode(void* Data, void* Key);
Chaining* Insert(Chaining* head, void* Data, void* Key);
Chaining* Search(Chaining* head, void* Key);
Chaining* Delete(Chaining* head, void* Key);

#endif