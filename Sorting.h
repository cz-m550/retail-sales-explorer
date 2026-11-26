#pragma once
#include "Sales.h"
#include <vector>

using namespace std;

enum class SortBy { Quantity, LineValue };

inline bool comesBefore(const Sale& a, const Sale& b, SortBy field) {
    double left = field == SortBy::Quantity ? a.quantity : a.lineValue;
    double right = field == SortBy::Quantity ? b.quantity : b.lineValue;

    if (left != right) {
        return left > right;
    }
    if (a.description != b.description) {
        return a.description < b.description;
    }
    if (a.quantity != b.quantity) {
        return a.quantity > b.quantity;
    }
    return a.unitPrice > b.unitPrice;
}

void mergeSort(vector<Sale>& sales, SortBy field);
void quickSort(vector<Sale>& sales, SortBy field);
