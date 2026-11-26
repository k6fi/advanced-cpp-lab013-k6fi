# Sorting Algorithms Laboratory

## Objective
This lab focuses on two classic divide-and-conquer sorting strategies:

- merge sort
- quick sort

Students must implement both algorithms, compare their behavior, and reason about their asymptotic complexity.

## Required tasks
Students must implement the following operations:

- `mergeSort(values)`
- `quickSort(values)`
- helper routines for merge and partition logic
- checks for whether a vector is sorted

## Analysis expectations
Students should explain:

- the runtime complexity of merge sort in best, average, and worst cases;
- the runtime complexity of quick sort in best, average, and worst cases;
- why merge sort is stable and quick sort is often faster in practice on average;
- space complexity differences between the two algorithms;
- the effect of pivot selection on quick sort performance;
- when each algorithm is preferable for different input distributions.

## Important comparison points
Students should discuss:

- recursive structure and recursion depth;
- whether the algorithm is in-place or requires auxiliary storage;
- worst-case behavior on already sorted or reverse-sorted inputs;
- the role of partitioning in quick sort;
- how merge sort handles duplicates and large input sizes efficiently.
