#pragma once

#include <string>
#include <vector>

struct Sale {
    int rowId;
    std::string product;
    std::string country;
    int quantity;
    double unitPrice;

    double lineValue() const {
        return quantity * unitPrice;
    }
};

enum class SortBy { Quantity, LineValue };

inline bool comesBefore(const Sale& a, const Sale& b, SortBy field) {
    double left = field == SortBy::Quantity ? a.quantity : a.lineValue();
    double right = field == SortBy::Quantity ? b.quantity : b.lineValue();
    return left == right ? a.rowId < b.rowId : left > right;
}

std::vector<Sale> loadSales(const std::string& csvPath);
void mergeSort(std::vector<Sale>& sales, SortBy field);
void quickSort(std::vector<Sale>& sales, SortBy field);
