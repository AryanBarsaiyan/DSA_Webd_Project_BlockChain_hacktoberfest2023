#include<bits/stdc++.h>
using namespace std;
bool mycmp(pair<int,int>a,
            pair<int,int>b)
{
    double A=(double)a.second/a.first;
    double B=(double)b.second/a.first;
    return A<B;                                                                 
}


int main()
{
    int n;  cin>>n;
    vector<pair<int,int>> arr(n,{0,0});
    for(auto &i:arr){   cin>>i.first;   cin>>i.second;  }
    sort(arr.begin(),arr.end(),mycmp);                          //decending order of val/weigth ratio
    int capacity;   cin>>capacity;
    double val=0;
    for(auto i:arr){    
        if(capacity>=i.first){  capacity-=i.first;  val+=i.second ;   }
            else if(capacity<i.first && capacity>0){    val+=i.second*((double)capacity/i.first);  break;  }
                    else    break; 
        cout<<capacity<<endl; }
    cout<<val<<endl;

}