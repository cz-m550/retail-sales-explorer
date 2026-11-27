#include "Sales.h"
#include "Sorting.h"
#include <vector>

int median3(std::vector<Sale>& sales, int low, int mid, int high, SortBy field) {
	if (comesBefore(sales[low], sales[mid], field) != comesBefore(sales[low], sales[high], field))
		return low;
	if (comesBefore(sales[mid], sales[low], field) != comesBefore(sales[mid], sales[high], field))
		return mid;
	return high;
}

int partition(std::vector<Sale>& sales, int low, int high, SortBy field) {
	int mid = low + (high - low) / 2;
	int pivotID = median3(sales, low, mid, high, field);
	Sale pivot = sales[pivotID];

	std::swap(sales[pivotID], sales[high]);
	int lowTrack = low;

	for (int i = low; i < high; i++) {
		if (comesBefore(sales[i], pivot, field)) {
			std::swap(sales[i], sales[lowTrack]);
			lowTrack++;
		}
	}

	std::swap(sales[lowTrack], sales[high]);
	return lowTrack;
}

void QSHelper(std::vector<Sale>& sales, int low, int high, SortBy field) {
	//base case, index's meet
	if (low >= high)
		return;

	int pivot = partition(sales, low, high, field);
	QSHelper(sales, low, pivot - 1, field);
	QSHelper(sales, pivot + 1, high, field);

}

void quickSort(std::vector<Sale>& sales, SortBy field) {
	if (sales.size() <= 1)
		return;
	
	QSHelper(sales, 0, static_cast<int>(sales.size()) - 1, field);
}
