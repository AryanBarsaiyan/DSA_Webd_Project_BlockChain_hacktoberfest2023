#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Number of elements in the array: ";
    cin >> n;
    int low = 0, high = n - 1 , key;
    int a[n];
    cout<<"Enter the elements :";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout <<"Enter the key: ";
    cin >> key;
    while (low <= high)
    {
        int mid = (high + low) / 2;
        if (a[mid] == key)
        {
            cout << "The element is present is at position: " << mid+1;
            return 0;
        }
        else if (a[mid] > key)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    cout<<"key not found"<<endl;

    return 0;
}