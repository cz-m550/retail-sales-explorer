#pragma once
#include "Sales.h"
#include <vector>
using namespace std;

enum SortBy { Quantity, LineValue };

bool comesBefore(const Sale& a, const Sale& b, SortBy field);

void mergeSort(vector<Sale>& sales, SortBy field);
void quickSort(vector<Sale>& sales, SortBy field);
