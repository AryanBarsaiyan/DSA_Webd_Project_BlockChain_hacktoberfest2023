#include<iostream>
using namespace std;
void binary_no(int n)
{
    if(n==0)
         return;
    binary_no(n/2);
    cout<<n%2<<" ";
}
int main()
{
    int n;
    cin>>n;
    binary_no(n);
}