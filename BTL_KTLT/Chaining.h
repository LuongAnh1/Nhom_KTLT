#ifndef CHAINING_H
#define CHAINING_H
#include "Data.h"

Chaining* CreatNode(void* Data);
void Insert(Chaining* head, void* Data, void* Key);
Chaining* Search(Chaining* head, void* Key);
void Delete(Chaining* head, void* Key);

#endif