#pragma once
#define swap(a, b)  \
    {               \
        int t = *a; \
        *a = *b;    \
        *b = t;     \
    }
inline void insertionSort(int *a, const int &n)
{
    int j, key; // defining the variables outside the loop decreased the time by 0.001 sec. for a sample size of size 100K
    for (int i = 1; i < n; i++)
	{
		key = a[i];
		for(j = i - 1;j >= 0 && a[j] > key; j--)
		{
			a[j + 1] = a[j];
		}
		a[j + 1] = key;
	}
}
inline void insertionSortInRange(int *a, const int &L, const int &H) // do insertion sort to a small portion of the array
{
    for (int i = L; i <= H; i++)
    {
        int currentValue = a[i];
        for (int j = i; j > 0 && a[j - 1] > currentValue; j--)
            swap(&a[j], &a[j - 1]);
    }

}