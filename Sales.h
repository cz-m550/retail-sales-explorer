#pragma once
#include <string>

struct Sale {
	std::string description;
	int quantity = 0;
	double unitPrice = 0.00;
	double lineValue = 0.00;
};


//struct Sale {
//    int rowId;
//    string product;
//    string country;
//    int quantity;
//    double unitPrice;
//
//    double lineValue() const {
//        return quantity * unitPrice;
//    }
//};
//
//enum class SortBy { Quantity, LineValue };
//
//inline bool comesBefore(const Sale& a, const Sale& b, SortBy field) {
//    double left = field == SortBy::Quantity ? a.quantity : a.lineValue();
//    double right = field == SortBy::Quantity ? b.quantity : b.lineValue();
//    return left == right ? a.rowId < b.rowId : left > right;
//}
//
//vector<Sale> loadSales(const string& csvPath);
//void mergeSort(vector<Sale>& sales, SortBy field);
//void quickSort(vector<Sale>& sales, SortBy field);
