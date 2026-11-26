#include "project/sorting.h"

#include <algorithm>
#include <stdexcept>

std::vector<int> SortingAlgorithms::mergeSort(const std::vector<int>& values) {
    (void)values;
    throw std::logic_error("Student implementation required: mergeSort");
}

std::vector<int> SortingAlgorithms::quickSort(const std::vector<int>& values) {
    (void)values;
    throw std::logic_error("Student implementation required: quickSort");
}

bool SortingAlgorithms::isSorted(const std::vector<int>& values) {
    for (std::size_t i = 1; i < values.size(); ++i) {
        if (values[i - 1] > values[i]) {
            return false;
        }
    }
    return true;
}

void SortingAlgorithms::mergeSortRecursive(std::vector<int>& values, std::size_t left, std::size_t right) {
    (void)values;
    (void)left;
    (void)right;
    throw std::logic_error("Student implementation required: mergeSortRecursive");
}

void SortingAlgorithms::merge(std::vector<int>& values, std::size_t left, std::size_t mid, std::size_t right) {
    (void)values;
    (void)left;
    (void)mid;
    (void)right;
    throw std::logic_error("Student implementation required: merge");
}

void SortingAlgorithms::quickSortRecursive(std::vector<int>& values, int low, int high) {
    (void)values;
    (void)low;
    (void)high;
    throw std::logic_error("Student implementation required: quickSortRecursive");
}

int SortingAlgorithms::partition(std::vector<int>& values, int low, int high) {
    (void)values;
    (void)low;
    (void)high;
    throw std::logic_error("Student implementation required: partition");
}
