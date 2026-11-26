cmake_minimum_required(VERSION 3.16)
project(RetailSalesExplorer LANGUAGES CXX)

add_executable(retail_sales main.cpp Sales.h dataLoader.h dataLoader.cpp)
target_compile_features(retail_sales PRIVATE cxx_std_17)
