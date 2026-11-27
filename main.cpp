// Test Main function shows example use of quickSort and dataLoader
//
//#include "Sales.h"
//#include "Sorting.h"
//#include "quickSort.h"
//#include "dataLoader.h"
//
//#include <algorithm>
//#include <iostream>
//#include <vector>
//
//int main() {
//    std::vector<Sale> sales;
//
//    if (!loadData("../../../resources/Online_Retail.csv", sales)) {
//        return 1;
//    }
//
//    // Sort in-place by passing the vector and a SortBy field
//    quickSort(sales, SortBy::LineValue);
//
//    size_t previewCount = std::min<size_t>(5, sales.size());
//    for (size_t i = 0; i < previewCount; ++i) {
//        std::cout << sales[i].description
//                  << " | qty: " << sales[i].quantity
//                  << " | unit: " << sales[i].unitPrice
//                  << " | total: " << sales[i].lineValue << "\n";
//    }
//
//    return 0;
//}
