#pragma once
#include "Sales.h"
#include "Sorting.h"
#include <vector>

int median3(std::vector<Sale>& sales, int low, int mid, int high, SortBy field);

int partition(std::vector<Sale>& sales, int low, int high, SortBy field);

void QSHelper(std::vector<Sale>& sales, int low, int high, SortBy field);

void quickSort(std::vector<Sale>& sales, SortBy field);