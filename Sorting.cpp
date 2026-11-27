#include "Sorting.h"

using namespace std;

bool comesBefore(const Sale& a, const Sale& b, SortBy field) {
    double left;
    double right;

    if (field == Quantity) {
        left = a.quantity;
        right = b.quantity;
    } else {
        left = a.lineValue;
        right = b.lineValue;
    }

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
