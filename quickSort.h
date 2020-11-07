#pragma once
#define swap(a, b)  \
    {               \
        int t = *a; \
        *a = *b;    \
        *b = t;     \
    }
inline int partitionLastElement(int *a, int L, int H)
{
    int pivot = a[H], i = (L - 1);

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
inline void utilityQuickSort(int *a, int L, int H)
{
    if (L < H)
    {
        int pivot = partitionLastElement(a, L, H);
        // those conditions reduced the running time by 0.01 sec for a sampole of size 100k
        if (pivot - L > 1)                     // If the left partition is larger than 1 element
            utilityQuickSort(a, L, pivot - 1); // Sort the left partition
        if (H - pivot > 1)                     // If the right partition is larger than 1 element
            utilityQuickSort(a, pivot + 1, H); // Sort the right partition
    }
}
inline void quickSort(int *a, const int &n)
{
    utilityQuickSort(a, 0, n - 1);
}
