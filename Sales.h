#pragma once
#include <string>

struct Sale {
	std::string description;
	int quantity = 0;
	double unitPrice = 0.00;
	double lineValue = 0.00;
};
