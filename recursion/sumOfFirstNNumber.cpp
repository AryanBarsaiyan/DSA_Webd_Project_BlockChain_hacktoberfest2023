#include<bits/stdc++.h>
using namespace std;

//parametarized recursion
// void add(int i , int sum){

//     if(i < 1){
//         cout<<sum;
//         return;
//     }   
//     add(i-1 , sum+i);
// }

//functional recursion
int add(int n){
    if(n == 0)
        return 0;
    return n + add(n-1);
}

int main(){

    cout<<add(10);
    return 0;
}