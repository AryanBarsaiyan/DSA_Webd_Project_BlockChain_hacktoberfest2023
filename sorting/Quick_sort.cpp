// Quick Sort in C++
#include <iostream>
using namespace std;

//function prototypes
int partition(int [], int, int);
void quickSort(int [], int, int);

int main()
{

	int arr[5],n = 5;
    cout<<"Enter 5 numbers:- ";
    for (int i = 0; i < 5; i++)
    {
        cin>>arr[i];
    }	

    //calling the quicksort function
	quickSort(arr, 0, n - 1);

    cout<<"After sorting the numbers:- ";
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}

	return 0;
}

//partition function
int partition(int arr[], int start, int end)
{

	int pivot = arr[start];

	int count = 0;
	for (int i = start + 1; i <= end; i++) {
		if (arr[i] <= pivot)
			count++;
	}

	// Giving pivot element its correct position
	int pivotIndex = start + count;
	swap(arr[pivotIndex], arr[start]);

	// Sorting left and right parts of the pivot element
	int i = start, j = end;

	while (i < pivotIndex && j > pivotIndex) {

		while (arr[i] <= pivot) {
			i++;
		}

		while (arr[j] > pivot) {
			j--;
		}

		if (i < pivotIndex && j > pivotIndex) {
			swap(arr[i++], arr[j--]);
		}
	}

	return pivotIndex;
}

//quick sort function
void quickSort(int arr[], int start, int end)
{

	// base case
	if (start >= end)
		return;

	// partitioning the array
	int p = partition(arr, start, end);

	// Sorting the left part
	quickSort(arr, start, p - 1);

	// Sorting the right part
	quickSort(arr, p + 1, end);
}