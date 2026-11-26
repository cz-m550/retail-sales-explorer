#include "Sales.h"
#include "dataLoader.h"

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using std::vector;
using std::string;

namespace {

	//handles product names that contain commas (,) inside quotation marks ("...")
	vector<string> parseCSVLine(const string& line) {
		vector<string> fields;
		string current;
		bool inQuotes = false;

		for (size_t i = 0; i < line.size(); i++) {
			char ch = line[i];

			//checking for double quotes ("") next to eachother which indicates a single literal quote (") in windows CSV
			if (ch == '"') {
				if (inQuotes && i + 1 < line.size() && line[i + 1] == '"') {
					current.push_back('"');
					++i;
				}
				else {
					inQuotes = !inQuotes;
				}
			}
			else if (ch == ',' && !inQuotes) {
				fields.push_back(current);
				current.clear();
			}
			else {
				current.push_back(ch);
			}
		}
		fields.push_back(current);
		return fields;
	}


	//handles Windows .CSV CRLF formating. Clears trailing \r from line end
	void removeCR(string& s) {
		if (!s.empty() && s.back() == '\r') {
			s.pop_back();
		}
		return;
	}

}

bool loadData(const string& filename, vector<Sale>& sales) {
	std::ifstream file(filename);
	string line;

	//safety checks: file opens, file isnt empty
	if (!file.is_open()) {
		std::cerr << "Couldn't open file" << std::endl;
		return false;
	}
	if (!std::getline(file, line)) {
		std::cerr << "File empty" << std::endl;
		return false;
	}

	//track lines in case of line errors
	size_t lineNumber = 1;
	while (std::getline(file, line)) {
		lineNumber++;
		removeCR(line);

		//skip in case of empty line
		if (line.empty())
			continue;

		//indexing 0-7
		// 0.InvoiceNumber | 1.StockCode | 2.Description | 3.Quantity | 4.InvoideDate | 5.UnitPrice | 6.CustomerID | 7.Country 
		vector<string> info = parseCSVLine(line);

		//check bad line
		if (info.size() < 6) {
			std::cerr << "Error on line: " << lineNumber << std::endl;
		}

		Sale s;
		s.description = info[2];
		try {
			s.quantity = std::stoi(info[3]);
			s.unitPrice = std::stod(info[5]);
		}
		catch (const std::exception&) {
			std::cerr << "Invalid number on line " << lineNumber << std::endl;
			continue;
		}
		s.lineValue = s.quantity * s.unitPrice;
		sales.push_back(s);
	}

	return true;
}
