#include<bits/stdc++.h>
using namespace std;


int main()
{
    int a[]={2,8,30,15,25,12};
    set<int>s;
    cout<<"-1 ";
    s.insert(a[0]);
    for(int i=1;i<6;i++)
    {
        auto it = s.lower_bound(a[i]);
        if(it != s.end())
            cout<<*it<<" ";
        else
            cout<<-1<<" ";
        s.insert(a[i]);
    }
    
}