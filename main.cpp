#include <iostream>
#include "Sales.h"

using namespace std;

int main() {
    cout << "Retail Sales Explorer\n";
}


//Test Main function
//#include "Sales.h"
//#include "dataLoader.h"
//
//#include <algorithm>
//#include <iostream>
//#include <string>
//#include <vector>
//#include <filesystem>
//
//int main() {
//
//    std::vector<Sale> sales;
//
//    if (!loadData("../../../resources/Online_Retail.csv", sales)) {
//        return 1;
//    }
//
//    std::cout << "Loaded " << sales.size() << " rows." << std::endl;
//    size_t previewCount = std::min<size_t>(5, sales.size());
//    for (size_t i = 0; i < previewCount; ++i) {
//        std::cout << sales[i].description
//            << " | qty: " << sales[i].quantity
//            << " | unit: " << sales[i].unitPrice
//            << " | total: " << sales[i].lineValue << "\n";
//    }
//
//    return 0;
//}
