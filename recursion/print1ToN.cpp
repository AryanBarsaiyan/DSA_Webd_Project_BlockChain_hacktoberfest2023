#include<bits/stdc++.h>
using namespace std;

void print(int s , int n){

    if(s > n)
        return;
    cout<<s<<endl;
    print(s+1 , n);
}

int main(){

    print(1 , 10);
    return 0;
}