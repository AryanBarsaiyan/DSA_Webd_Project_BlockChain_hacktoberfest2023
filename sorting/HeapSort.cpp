#include <iostream>
using namespace std;

static void heapsort(int Array[], int n);
static void heapify(int Array[], int n, int i);
static void PrintArray(int Array[], int n);

// function for heap sort which calls heapify function 
// to build the max heap and then swap last element of 
// the max-heap with the first element
// exclude the last element from the heap and rebuild the heap
static void heapsort(int Array[], int n) {
  int temp;

  for(int i = n/2; i >= 0; i--) {
    heapify(Array, n-1, i);
  }
  
  for(int i = n - 1; i >= 0; i--) {
    //swap last element of the max-heap with the first element
    temp = Array[i];
    Array[i] = Array[0];
    Array[0] = temp;

    //exclude the last element from the heap and rebuild the heap 
    heapify(Array, i-1, 0);
  }
}

// heapify function is used to build the max heap
// max heap has maximum element at the root which means
// first element of the array will be maximum in max heap
static void heapify(int Array[], int n, int i) {
  int max = i;
  int left = 2*i + 1;
  int right = 2*i + 2;

  //if the left element is greater than root
  if(left <= n && Array[left] > Array[max]) {
    max = left;
  }

  //if the right element is greater than root
  if(right <= n && Array[right] > Array[max]) {
    max = right;
  }

  //if the max is not i
  if(max != i) {
    int temp = Array[i];
    Array[i] = Array[max];
    Array[max] = temp;
    //Recursively heapify the affected sub-tree
    heapify(Array, n, max); 
  }
}

// function to print array
static void PrintArray(int Array[], int n) { 
  for (int i=0; i<n; i++) 
    cout<<Array[i]<<" "; 
  cout<<"\n"; 
} 

// test the code
int main () {
  int MyArray[] = {10, 1, 23, 50, 7, -4};
  int n = sizeof(MyArray) / sizeof(MyArray[0]); 
  cout<<"Original Array\n";
  PrintArray(MyArray, n);

  heapsort(MyArray, n);
  cout<<"\nSorted Array\n";
  PrintArray(MyArray, n);
  return 0;
}
