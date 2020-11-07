#include <iostream>
#include <fstream>
#include <chrono>
#include "hybridSort.h"
#include "mergeSort.h"
#include "quickSort.h"
using namespace std;

// In vs code terminal, type cmd first!
// python smaples.py 10000 randomSample.txt
// g++ -O3 main.cpp -o out
// out 1 randomSample.txt sortedSample.txt 
/****************************************** Utilities *********************************************************/
bool isSorted(int *a, const int &n)
{
	bool sorted = true;
	for (int i = 0; i < n; i++)
	{
		if (a[i] > a[i + 1])
			sorted = false;
	}
	return sorted;
}
double doSorting(int *a, int sampleSize, void (*sort)(int *, const int &))
{
//
#define end chrono::high_resolution_clock::now()
#define TimeElapsed(start) chrono::duration_cast<chrono::duration<double>>(end - start)
//

	chrono::high_resolution_clock::time_point start;

	start = chrono::high_resolution_clock::now();
	sort(a, sampleSize);

	return TimeElapsed(start).count();
}
void printSortingStatus(int *a, int size, string sortingAlgo, double sortingTime)
{
	std::cout << "Sorting Algorithm: " << sortingAlgo << "\n";
	std::cout << "Sample Size: " << size - 1 << "\n";
	std::cout << "Sorting Time:      " << sortingTime << " sec.\n";
	std::cout << "SORTED:            " << boolalpha << isSorted(a, size - 1) << "\n";
}
int readData(string name, int *&a)
{
	ifstream in;
	in.open(name);
	int size, i = 0;
	while (!in.eof())
	{
		in >> a[i++];
	}

	return i;
}
void writeSortedData(string name, int *a, int size)
{
	ofstream out;
	out.open(name);
	for (int i = 0; i < size; i++)
		out << a[i] << " ";
}
/******************************************** Main *********************************************************/
#define initialSampleSize 500050
int main(int numArg, char **args) // arg[1] = sortingAlgo, arg[2] = input file, arg[3] = sorted sample file
{
	if (numArg < 3)
	{
		cout << "INVALID INPUT FORMAT!!!\n";
		return 0;
	}
	string inputFileName = args[2];
	string sortedDataFileName = args[3];
	string sortingAlgo = "";
	int *a = new int[initialSampleSize];
	int size, numOP = atoi(args[1]);

	size = readData(inputFileName, a);
	if (size == 0 || size == 1)
		return 0;
	double sortingTime = 0;
	switch (numOP)
	{
	case 1:
	{
        void (*hybridS)(int *, const int &) = hybridSort;
		sortingTime = doSorting(a, size, hybridS);
		sortingAlgo = "Hyprid Sort";
		break;
	}
	case 2:
	{
		void (*insertS)(int *, const int &) = insertionSort;
		sortingTime = doSorting(a, size, insertS);
		sortingAlgo = "Insertion Sort";
		break;
	}
	case 3:
	{
		void (*mergeS)(int *, const int &) = mergeSort;
		sortingTime = doSorting(a, size, mergeS);
		sortingAlgo = "Merge Sort";
		break;
	}
	case 4:
	{
		void (*hybridMS)(int *, const int &) = hybridMergeSort;
		sortingTime = doSorting(a, size, hybridMS);
		sortingAlgo = "Hyprid Merge Sort";
		break;
	}
	case 5:
	{
		void (*quickS)(int *, const int &) = quickSort;
		sortingTime = doSorting(a, size, quickS);
		sortingAlgo = "Quick Sort";
		break;
	}
	case 6:
	{
		void (*hybridQS)(int *, const int &) = hybridQuickSort;
		sortingTime = doSorting(a, size, hybridQS);
		sortingAlgo = "Hyprid Quick Sort";
		break;
	}
	default:
	{
		cout << "INVALID ALGORITHM NUMBER!!!\n";
		return 0;
	}
	}

	writeSortedData(sortedDataFileName, a, size);
	printSortingStatus(a, size, sortingAlgo, sortingTime);
}