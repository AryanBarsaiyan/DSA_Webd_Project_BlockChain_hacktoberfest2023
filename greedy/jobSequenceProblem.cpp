#include<bits/stdc++.h>
using namespace std;
bool sortbysec(pair<int,int> &a,
                pair<int,int> &b)
{
    return (a.second > b.second);
}


int main()
{
    int n;  cin>>n;
    vector<pair<int,int>>   arr(n,{0,0});
    for(auto &i:arr){   cin>>i.first;   cin>>i.second;   }
    sort(arr.begin(),arr.end(),sortbysec);
    int MAX=INT16_MIN;
    for(auto i:arr) if(i.first>MAX) MAX=i.first;
    vector<bool> vis(MAX,0);
    int profit=0;
    for(auto i:arr){
        for(int j=i.first-1;j>=0;j--)
            if(vis[j]==false)
            {
                profit+=i.second;
                vis[j]=true;
                break;
            }
    }
    cout<<profit<<endl;
}