#include <iostream>
#include <vector>

#include "project/sorting.h"

int main() {
    std::vector<int> values = {9, 4, 7, 1, 3, 8, 2, 6, 5};

    std::vector<int> merged = SortingAlgorithms::mergeSort(values);
    std::vector<int> quick = SortingAlgorithms::quickSort(values);

    std::cout << "Merge sort: ";
    for (int value : merged) {
        std::cout << value << " ";
    }
    std::cout << "\n";

    std::cout << "Quick sort: ";
    for (int value : quick) {
        std::cout << value << " ";
    }
    std::cout << "\n";

    return 0;
}
