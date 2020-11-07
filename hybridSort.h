#pragma once
#include"insertionSort.h"
#include "hybridMergeSort.h"
#include "hybridQuickSort.h"
#define MIN_SIZE 50                                           // if the array is less than this value, do insertion sort. This value is calibrated
int howMuchSorted(int* a, const int &n) // determining how much the array is sorted to choose the proper sorting algorithm
{
	int sorted;
	for (int i = 0; i < n; i++)
	{
		if (a[i] <= a[i + 1]) // count how many pairs are sorted
			sorted++;
	}
	return sorted;
}
inline void hybridSort(int *a, const int &n)
{
    // first check how much the array is sorted
    int numSorted = howMuchSorted(a, n-1);
    if (numSorted >= 0.9 * n)
    {
        insertionSort(a, n);
    }
    else if (numSorted >= 0.6 * n) // if the array is more sorted, hybridQuickSort isn't a good choice! 
    {
        hybridMergeSort(a, n); // since for nearly sorted the hybridMergeSort is better than the normal merge sort
    }
    else
    {
        hybridQuickSort(a, n);
    }
    
}