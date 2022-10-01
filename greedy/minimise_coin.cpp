// minimise the coin for certian amount
#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main()
{                                                   //works only for indian currency
    int n;  cin>>n;
    vector<int> arr(n,0);
    for(auto &i:arr)    cin>>i;
    sort(arr.begin(),arr.end(),greater<int>());
    int money,coin=0;  cin>>money;
    for(auto i:arr)
    {
        coin+=money/i;
        money=money%i;
        if(money==0)
            break;
    }
    cout<<coin<<endl;
}