#include<bits/stdc++.h>
using namespace std;
void swap(int &a,int &b)
{
    int x=b;
    b=a;
    a=x;
}
void bubble_sort(int arr[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        bool vis=false;
        for(int j=0;j<n-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                swap(arr[j],arr[j+1]);
                vis=true;
            }
        }
        if(!vis)
            break;
    }
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    bubble_sort(arr,n);
    for(int i=0;i<n;i++)
        cout<<arr[i];
}