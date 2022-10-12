#include<bits/stdc++.h>
using namespace std;

void print(int s , int n){

    if(s > n)
        return;
    print(s+1 , n);
    cout<<s<<endl;
}

int main(){

    print(1 , 10);
    return 0;
}