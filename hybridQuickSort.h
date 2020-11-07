#pragma once
#include"insertionSort.h"
#define MIN_SIZE 50                                           // if the array is less than this value, do insertion sort. This value is calibrated
#define swap(a, b)  \
    {               \
        int t = *a; \
        *a = *b;    \
        *b = t;     \
    }
inline int partitionMedianElement(int *a, int L, int H)
{
    // 1. get the median M
    int M = L + (H - L) / 2; // l + (r - l)/2 = (2l/2) + (r - l)/2 = (l + r) / 2. But, now we can avoid any overflow
    if (a[L] > a[H])
        swap(&a[L], &a[H]);
    if (a[M] > a[H])
        swap(&a[M], &a[H]);
    if (a[L] > a[M])
        swap(&a[L], &a[M]);

    //2.  after getting the median, put it at the end of the array and continue your normal quicksort
    swap(&a[M], &a[H]);
    int pivot = a[H];
    int i = (L - 1);

    for (int j = L; j <= H - 1; j++)
    {
        if (a[j] < pivot)
        {
            i++;
            swap(&a[i], &a[j]);
        }
    }
    swap(&a[i + 1], &a[H]);
    return (i + 1);
}
inline void utilityHybridQuickSort(int *a, int L, int H)
{
    if (L < H)
    {
        if ((H - L) < MIN_SIZE) // If the partition size is less than the MIN_SIZE, use insertion sort as it is faster for small partitions
        {
            insertionSortInRange(a, L, H);
            return;
        }
        int pivot = partitionMedianElement(a, L, H);
        if (pivot - L > 1)                      // If the left partition is larger than 1 element
            utilityHybridQuickSort(a, L, pivot - 1); // Sort the left partition

        if (H - pivot > 1)                      // If the right partition is larger than 1 element
            utilityHybridQuickSort(a, pivot + 1, H); // Sort the right partition
    }
}
inline void hybridQuickSort(int *a, const int &n)
{
    utilityHybridQuickSort(a, 0, n - 1);
}
