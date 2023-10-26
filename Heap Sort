#include <bits/stdc++.h>
using namespace std;
void MaxHeapify(int arr[], int i, int n)
{
    while (2 * i <= n)
    {
        int left = 2 * i;
        int right = 2 * i + 1;
        int mx = left;
        if (right <= n)
        {
            if (arr[right] > arr[left])
            {
                mx = right;
            }
        }
        if (arr[mx] > arr[i])
        {
            swap(arr[mx], arr[i]);
        }
        else
        {
            break;
        }
        i = mx;
    }
}
void Build_Max_heap(int arr[], int n)
{
    for (int i = n / 2; i >= 1; i--)
    {
        MaxHeapify(arr, i, n);
    }
}
void Heap_sort(int arr[], int n)
{
    Build_Max_heap(arr, n);
    for (int j = n; j >= 2; j--)
    {
        swap(arr[1], arr[j]);
        MaxHeapify(arr, 1, j - 1);
    }
}
int main()
{
    int n;
    cin >> n;
    int arr[n + 1];
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    Heap_sort(arr, n);
    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
}
