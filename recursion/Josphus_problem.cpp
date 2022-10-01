#include<iostream>
using namespace std;
int soltuion(int n,int k)
{
    if(n==1)
        return 0;
    return (soltuion(n-1,k) + k)%n;
}
int main()
{
    int n,k;
    cin>>n>>k;
    cout<<soltuion(n,k);
}