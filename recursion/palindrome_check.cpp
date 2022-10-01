#include<bits/stdc++.h>
using namespace std;
bool palindrome(string str ,int start,int end)
{
    if(str[start]!=str[end])
        return 0;
    if(start==end || end==start+1)
        return 1;
    return palindrome(str,start+1,end-1);
}
bool is_pal(string &str,int start,int end)
{
    if(start>=end)
        return 1;

    return ((str[start]==str[end]) && is_pal(str,start+1,end-1));
}
int main()
{
    string str;
    cin>>str;
    int n=str.length();
    cout<<palindrome(str,0,n-1)<<endl;
    cout<<is_pal(str,0,n-1);
}
