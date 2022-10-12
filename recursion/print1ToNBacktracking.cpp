#include<bits/stdc++.h>
using namespace std;

void print(int s , int n){

    if(s < 1)
        return;
    print(s-1 , n);
    cout<<s<<endl;
}

int main(){

    print(10 , 10);
    return 0;
}