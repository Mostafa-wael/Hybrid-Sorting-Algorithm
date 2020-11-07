# Hybrid Sorting Algorithm
---
## Objective:
-	Creating a hybrid sorting algorithm that is independent of the input sample size and its sorting status.

## Approach:
-	Creating a hybrid optimized version of the merge and quick sorts.
-	Checking the sorting status of the list to choose the proper algorithm to procced with it.
- If more than 90% of the list were sorted, Insertion sort is chosen since, it has the least running time for sorted lists.
- If less than 90% and more than 60% of the list were sorted, hybrid merge sort proved to have the least running time for the semi-sorted lists.
- If less than 60% of the list were sorted, hybrid quick sort proved to have the least running time for the unsorted lists.

### Hybrid Quick Sort:
-	Choosing a pivot that represents the median value of the first, middle and last elements.
-	If the size of the list after portioning is less than a specified threshold, an adapted version of insertion sort is used since that, it proved to have the least running time for small lists regardless of their sorting status.

### Hybrid Merge Sort:
-	If the size of the list after portioning is less than a specified threshold, an adapted version of insertion sort is used since that, it proved to have the least running time for small lists regardless of their sorting status.

## Achievements:
- Creating a hybrid quick sort that is two times faster than the normal quick sort for sorted lists.
-	Crating a hybrid sort that has the best-case time complexity (O(nlogn)) for any input size regardless of the data being sorted or not.



