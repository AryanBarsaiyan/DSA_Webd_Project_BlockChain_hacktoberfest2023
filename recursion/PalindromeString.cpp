#include<bits/stdc++.h>
using namespace std;

bool palindrome(string name , int i , int n){

    if(i >= n/2)
        return true;
    if(name[i] != name[n-i-1])
        return false;
    return palindrome(name, i+1 , n);
}

int main(){

    string name = "MadaM";
    int n = name.size();
    if(palindrome(name , 0 , n))
        cout<<"String is palindrome";
    else
        cout<<"String is not palindrome";
    return 0;
}