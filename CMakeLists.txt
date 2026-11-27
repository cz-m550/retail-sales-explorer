cmake_minimum_required(VERSION 3.16)
project(RetailSalesExplorer)
set(CMAKE_CXX_STANDARD 17)
add_executable(retail_sales
        main.cpp
        dataLoader.cpp
        Sorting.cpp
        MergeSort.cpp
        quickSort.cpp
)
