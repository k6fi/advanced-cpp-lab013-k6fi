#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "project/sorting.h"

#include <algorithm>
#include <stdexcept>
#include <vector>

TEST_CASE("merge sort handles empty input") {
    std::vector<int> values;
    auto result = SortingAlgorithms::mergeSort(values);
    REQUIRE(result.empty());
}

TEST_CASE("merge sort sorts a mixed integer list") {
    std::vector<int> values = {9, 4, 7, 1, 3, 8, 2, 6, 5};
    auto result = SortingAlgorithms::mergeSort(values);
    REQUIRE(SortingAlgorithms::isSorted(result));
    REQUIRE(result == std::vector<int>({1, 2, 3, 4, 5, 6, 7, 8, 9}));
}

TEST_CASE("merge sort handles duplicates and negatives") {
    std::vector<int> values = {5, -2, 7, -2, 8, 0, 5, -10, 12};
    auto result = SortingAlgorithms::mergeSort(values);
    REQUIRE(SortingAlgorithms::isSorted(result));
    REQUIRE(result == std::vector<int>({-10, -2, -2, 0, 5, 5, 7, 8, 12}));
}

TEST_CASE("merge sort keeps already sorted input unchanged in order") {
    std::vector<int> values = {1, 2, 3, 4, 5};
    auto result = SortingAlgorithms::mergeSort(values);
    REQUIRE(result == std::vector<int>({1, 2, 3, 4, 5}));
}

TEST_CASE("quick sort handles empty input") {
    std::vector<int> values;
    auto result = SortingAlgorithms::quickSort(values);
    REQUIRE(result.empty());
}

TEST_CASE("quick sort sorts a mixed integer list") {
    std::vector<int> values = {9, 4, 7, 1, 3, 8, 2, 6, 5};
    auto result = SortingAlgorithms::quickSort(values);
    REQUIRE(SortingAlgorithms::isSorted(result));
    REQUIRE(result == std::vector<int>({1, 2, 3, 4, 5, 6, 7, 8, 9}));
}

TEST_CASE("quick sort handles repeated values and negatives") {
    std::vector<int> values = {4, -1, 4, 0, -5, 3, 4, 2, -1};
    auto result = SortingAlgorithms::quickSort(values);
    REQUIRE(SortingAlgorithms::isSorted(result));
    REQUIRE(result == std::vector<int>({-5, -1, -1, 0, 2, 3, 4, 4, 4}));
}

TEST_CASE("quick sort keeps descending input sorted correctly") {
    std::vector<int> values = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    auto result = SortingAlgorithms::quickSort(values);
    REQUIRE(SortingAlgorithms::isSorted(result));
    REQUIRE(result == std::vector<int>({1, 2, 3, 4, 5, 6, 7, 8, 9}));
}

TEST_CASE("sorting algorithms produce the same results on the same input") {
    std::vector<int> values = {12, 3, 17, 9, 5, 8, 1, 7, 13, 11};
    auto mergeResult = SortingAlgorithms::mergeSort(values);
    auto quickResult = SortingAlgorithms::quickSort(values);

    REQUIRE(mergeResult == quickResult);
    REQUIRE(SortingAlgorithms::isSorted(mergeResult));
    REQUIRE(SortingAlgorithms::isSorted(quickResult));
}

TEST_CASE("isSorted correctly reports sorted and unsorted vectors") {
    std::vector<int> sorted = {1, 2, 3, 4, 5};
    std::vector<int> unsorted = {1, 5, 2, 4, 3};
    std::vector<int> equal = {3, 3, 3, 3};

    REQUIRE(SortingAlgorithms::isSorted(sorted));
    REQUIRE_FALSE(SortingAlgorithms::isSorted(unsorted));
    REQUIRE(SortingAlgorithms::isSorted(equal));
}

TEST_CASE("sorting functions do not mutate the original input order") {
    std::vector<int> values = {6, 1, 5, 2, 4, 3};
    std::vector<int> original = values;

    auto mergeResult = SortingAlgorithms::mergeSort(values);
    auto quickResult = SortingAlgorithms::quickSort(values);

    REQUIRE(values == original);
    REQUIRE(mergeResult != values);
    REQUIRE(quickResult != values);
}

TEST_CASE("merge sort and quick sort handle a single element") {
    std::vector<int> values = {42};
    auto mergeResult = SortingAlgorithms::mergeSort(values);
    auto quickResult = SortingAlgorithms::quickSort(values);

    REQUIRE(mergeResult == std::vector<int>({42}));
    REQUIRE(quickResult == std::vector<int>({42}));
    REQUIRE(SortingAlgorithms::isSorted(mergeResult));
    REQUIRE(SortingAlgorithms::isSorted(quickResult));
}

TEST_CASE("merge sort and quick sort handle all equal values") {
    std::vector<int> values = {7, 7, 7, 7, 7, 7};
    auto mergeResult = SortingAlgorithms::mergeSort(values);
    auto quickResult = SortingAlgorithms::quickSort(values);

    REQUIRE(mergeResult == std::vector<int>({7, 7, 7, 7, 7, 7}));
    REQUIRE(quickResult == std::vector<int>({7, 7, 7, 7, 7, 7}));
}

TEST_CASE("sorting handles reverse sorted input") {
    std::vector<int> values = {20, 19, 18, 17, 16, 15, 14, 13, 12, 11};
    auto mergeResult = SortingAlgorithms::mergeSort(values);
    auto quickResult = SortingAlgorithms::quickSort(values);

    REQUIRE(mergeResult == std::vector<int>({11, 12, 13, 14, 15, 16, 17, 18, 19, 20}));
    REQUIRE(quickResult == std::vector<int>({11, 12, 13, 14, 15, 16, 17, 18, 19, 20}));
}

TEST_CASE("sorting handles alternating high and low values") {
    std::vector<int> values = {5, -5, 5, -5, 5, -5, 5, -5, 5};
    auto mergeResult = SortingAlgorithms::mergeSort(values);
    auto quickResult = SortingAlgorithms::quickSort(values);

    REQUIRE(SortingAlgorithms::isSorted(mergeResult));
    REQUIRE(SortingAlgorithms::isSorted(quickResult));
    REQUIRE(mergeResult == std::vector<int>({-5, -5, -5, -5, -5, 5, 5, 5, 5}));
    REQUIRE(quickResult == std::vector<int>({-5, -5, -5, -5, -5, 5, 5, 5, 5}));
}

TEST_CASE("sorting preserves duplicate counts exactly") {
    std::vector<int> values = {3, 1, 3, 2, 3, 1, 2, 3};
    auto mergeResult = SortingAlgorithms::mergeSort(values);
    auto quickResult = SortingAlgorithms::quickSort(values);

    REQUIRE(std::count(mergeResult.begin(), mergeResult.end(), 1) == 2);
    REQUIRE(std::count(mergeResult.begin(), mergeResult.end(), 2) == 2);
    REQUIRE(std::count(mergeResult.begin(), mergeResult.end(), 3) == 4);
    REQUIRE(std::count(quickResult.begin(), quickResult.end(), 1) == 2);
    REQUIRE(std::count(quickResult.begin(), quickResult.end(), 2) == 2);
    REQUIRE(std::count(quickResult.begin(), quickResult.end(), 3) == 4);
}
