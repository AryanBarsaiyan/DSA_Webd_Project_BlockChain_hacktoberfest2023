#include<bits/stdc++.h>
using namespace std;

void reverse(int arr[] , int left , int right){
    if(left >= right)
        return;

    swap(arr[left] , arr[right]);
    reverse(arr , left+1 , right-1);
}

int main(){

    int arr[] = {1,2,3,4,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    reverse(arr,0,n-1);
    for(int i = 0 ; i<n ; i++)
        cout<<arr[i]<<" ";
    return 0;
}