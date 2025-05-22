#ifndef MERGESORT_H
#define MERGESORT_H
#include "Data.h"

void Split(Chaining* source, Chaining** frontRef, Chaining** backRef);
void MergeSort(Chaining* left, Chaining* right);


#endif