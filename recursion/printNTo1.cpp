#include<bits/stdc++.h>
using namespace std;

void print(int n){

    if(n < 1)
        return;
    cout<<n<<endl;
    print(n-1);
}

int main(){

    print(10);
    return 0;
}