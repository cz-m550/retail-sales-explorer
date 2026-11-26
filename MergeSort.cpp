#include "Sales.h"

using namespace std;

static void merge(vector<Sale>& sales, vector<Sale>& temp,
                  size_t left, size_t mid, size_t right, SortBy field) {
    size_t i = left;
    size_t j = mid;
    size_t k = left;

    while (i < mid && j < right) {
        if (comesBefore(sales[j], sales[i], field)) {
            temp[k++] = sales[j++];
        } else {
            temp[k++] = sales[i++];
        }
    }

    while (i < mid) {
        temp[k++] = sales[i++];
    }

    while (j < right) {
        temp[k++] = sales[j++];
    }

    for (size_t index = left; index < right; index++) {
        sales[index] = temp[index];
    }
}

static void mergeSortHelper(vector<Sale>& sales, vector<Sale>& temp,
                            size_t left, size_t right, SortBy field) {
    if (right - left <= 1) {
        return;
    }

    size_t mid = left + (right - left) / 2;
    mergeSortHelper(sales, temp, left, mid, field);
    mergeSortHelper(sales, temp, mid, right, field);
    merge(sales, temp, left, mid, right, field);
}

void mergeSort(vector<Sale>& sales, SortBy field) {
    vector<Sale> temp(sales.size());
    mergeSortHelper(sales, temp, 0, sales.size(), field);
}
