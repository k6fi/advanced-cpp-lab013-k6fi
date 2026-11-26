#pragma once

#include <cstddef>
#include <stdexcept>
#include <vector>

class SortingAlgorithms {
public:
    static std::vector<int> mergeSort(const std::vector<int>& values);
    static std::vector<int> quickSort(const std::vector<int>& values);
    static bool isSorted(const std::vector<int>& values);

private:
    static void mergeSortRecursive(std::vector<int>& values, std::size_t left, std::size_t right);
    static void merge(std::vector<int>& values, std::size_t left, std::size_t mid, std::size_t right);
    static void quickSortRecursive(std::vector<int>& values, int low, int high);
    static int partition(std::vector<int>& values, int low, int high);
};
