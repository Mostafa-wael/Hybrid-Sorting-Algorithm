#pragma once
#include"insertionSort.h"
#define MIN_SIZE 50                                           // if the array is less than this value, do insertion sort. This value is calibrated
#define swap(a, b)  \
    {               \
        int t = *a; \
        *a = *b;    \
        *b = t;     \
    }
inline void utilityHybridMerge(int *a, int l, int m, int r) // a: l-----m-----r
{
    // 1. create two new arrays
    const int szL = m - l + 1, szR = r - m;
    int *L = new int[szL];
    int *R = new int[szR];
    for (int i = 0; i < szL; i++)
        L[i] = a[l + i];
    for (int j = 0; j < szR; j++)
        R[j] = a[m + 1 + j];

    // 2. merge the two new arrays into a new ordered array
    int i = 0, j = 0, k = l; // k is the begining of the merged aay

    while (i < szL && j < szR)
        if (L[i] <= R[j])
            a[k++] = L[i++];
        else
            a[k++] = R[j++];
    while (i < szL)
        a[k++] = L[i++];

    while (j < szR)
        a[k++] = R[j++];
}
inline void utilityHybridMergeSort(int *a, int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2; // l + (r - l)/2 = (2l/2) + (r - l)/2 = (l + r) / 2. But, now we can avoid any overflow

        if ((r - l) < MIN_SIZE) // If the partition size is less than the MIN_SIZE, use insertion sort as it is faster for small partitions
        {
            insertionSortInRange(a, l, r);
        }
        else
        {
            utilityHybridMergeSort(a, l, m);
            utilityHybridMergeSort(a, m + 1, r);
        }

        utilityHybridMerge(a, l, m, r);
    }
}
inline void hybridMergeSort(int *a, const int &n) // for random data, normal merge is faster by ratio 2.59:0.0159 but for sorted data 0.002:0.0149
{
    utilityHybridMergeSort(a, 0, n - 1);
}
