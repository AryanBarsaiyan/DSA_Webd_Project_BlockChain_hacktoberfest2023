#include<bits/stdc++.h>
using namespace std;
void res(int a[],int n,int k)
{
    unordered_map<int,int> m;
    for(int i=0;i<n;i++)
    {
        if(m.find(a[i])!=m.end())
            m[a[i]]++;
        else if(m.size()<k-1)
            m.insert({a[i],1});
        else
        {
            for(auto &x:m)
            {
            	x.second--;
            	if(x.second==0)
            	m.erase(x.first);
			}
            	
        }
    }

    for(auto at=m.begin();at!=m.end();at++)
    {
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(a[i]==(*at).first)
                count++;
    	}
        if(count>n/k)
            cout<<(*at).first<<"   ";
    }
}
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    int k;
    cin>>k;
    
    res(a,n,k);
}
