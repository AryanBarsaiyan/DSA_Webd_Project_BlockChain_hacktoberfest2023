#include<bits/stdc++.h>
using namespace std;
void count_window(int a[],int n,int k)
{
    unordered_map<int,int>m;
    for(int i=0;i<k;i++)
    {
        m[a[i]]++;
    }
    cout<<m.size()<<" ";
    for(int i=k;i<n;i++)
    {
        m[a[i-k]]--;                                                     //remove the 1st element;
        auto at=m.find(a[i-k]);
        if((*at).second==0)
            m.erase(a[i-k]);
        m[a[i]]++;                                                      //adding the last element of the window

        cout<<m.size()<<" ";
    }
}
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int k;
    cin>>k;
    count_window(a,n,k);
}