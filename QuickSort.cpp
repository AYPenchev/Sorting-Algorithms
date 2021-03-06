#include "pch.h"
#include <iostream>
#include <vector>

void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

int partition(int arr[], int low, int high)
{
	int pivot = arr[high];  
	int i = (low - 1);  

	for (int j = low; j <= high - 1; j++)
	{
		if (arr[j] <= pivot)
		{
			i++;   
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
	if (low < high)
	{
		int pi = partition(arr, low, high);

		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}
/*
void quickSortMiddle(std::vector<int> a, int left, int right)
{
	if (left >= right) return;

	int leftI = left;
	int rightI = right;

	int pivot = left + (right - left) / 2;

	while (leftI <= rightI)
	{
		while (a[leftI] < a[pivot])leftI++;
		while (a[rightI] > a[pivot])rightI--;

		if (leftI <= rightI)
		{
			swap(&a[leftI], &a[rightI]);
			leftI++;
			rightI--;
		}
	}

	if (left <= rightI)
	{
		quickSortMiddle(a, left, rightI);
	}

	if (leftI <= right)
	{
		quickSortMiddle(a, leftI, right);
	}
}*/

int main()
{
	/*std::vector<int> notSorted;
	notSorted.push_back(9);
	notSorted.push_back(5);
	notSorted.push_back(-1);
	notSorted.push_back(0);
	notSorted.push_back(3500);*/
	int notSorted[] = { 9, 5, -1, 0, 3500, 29 };
	int n = sizeof(notSorted) / sizeof(notSorted[0]);
	quickSort(notSorted, 0, n - 1);
	for (const auto i : notSorted)
	{
		std::cout << i << ' ';
	}
	return 0;
}