#include<bits/stdc++.h>
using namespace std;
int count_distinct(int arr[],int n)
{
    unordered_set<int> us(arr,arr+n);
    return us.size();
} 
int main()
{
    unordered_set<int> s;
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    for(int i=0;i<n;i++)
        s.insert(arr[i]);
    cout<<s.size()<<endl;
    cout<<count_distinct(arr,n);
}