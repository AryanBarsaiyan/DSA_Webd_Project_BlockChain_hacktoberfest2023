#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int *arr=new int [n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    unordered_map<int,int>m;
    for(int i=0;i<n;i++)
        m[arr[i]]++;
    for(auto x:m)
        cout<<x.first<<" "<<x.second<<endl;
        return 0;
}