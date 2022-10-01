#include<bits/stdc++.h>
using namespace std;
#define int long long
bool sortbysec(pair<int,int> &a,
                pair<int,int> &b)
{
    return (a.second < b.second);
}

int32_t main()
{
    int n;  cin>>n; 
    vector<pair<int,int>> PAIR(n,{0,0});
    for(auto &i:PAIR){  cin>>i.first;   cin>>i.second;   }
    sort(PAIR.begin(),PAIR.end(),sortbysec);
    int count=1,val=PAIR[0].second;
    for(auto i: PAIR){  if(i.first>=val){   count++;    val=i.second;  }   }
    cout<<count<<endl;
}