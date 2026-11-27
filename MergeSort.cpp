#include "Sorting.h"
using namespace std;
static void merge(vector<Sale>& sales, vector<Sale>& temp, size_t left, size_t middle, size_t right, SortBy field) {
    size_t i = left;
    size_t j = middle;
    size_t k = left;
    while (i < middle && j < right) {
        bool x = comesBefore(sales[j], sales[i], field);
        if (x) {
            temp[k] = sales[j];
            j++;
        } else {
            temp[k] = sales[i];
            i++;
        }
        k++;
    }
    while (i < middle) {
        temp[k] = sales[i];
        k++;
        i++;
    }
    while (j < right) {
        temp[k] = sales[j];
        k++;
        j++;
    }
    for (size_t index = left; index < right; index++) {
        sales[index] = temp[index];
    }
}
static void mergeSortHelper(vector<Sale>& sales, vector<Sale>& temp, size_t left, size_t right, SortBy field) {
    if (right - left <= 1) {
        return;
    }
    size_t middle = left + (right - left) / 2;
    mergeSortHelper(sales, temp, left, middle, field);
    mergeSortHelper(sales, temp, middle, right, field);
    merge(sales, temp, left, middle, right, field);
}
void mergeSort(vector<Sale>& sales, SortBy field) {
    vector<Sale> temp(sales.size());
    mergeSortHelper(sales, temp, 0, sales.size(), field);
}
