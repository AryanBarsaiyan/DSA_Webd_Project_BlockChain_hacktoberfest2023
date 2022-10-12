#include<bits/stdc++.h>
using namespace std;

int printSubseq(int arr[] , int sum , int val ,vector<int> &ans , int index , int size){

    if(index >= size){
        if(val == sum){
            return 1;
        }
        return 0;
    }

    //including
    ans.push_back(arr[index]);
    int l = printSubseq(arr, sum+arr[index], val ,ans, index+1, size);

    //not including
    ans.pop_back();
    int r = printSubseq(arr, sum, val , ans, index+1, size);
    return l + r;
}

int main(){
    int arr[] = {1,2,1};
    vector<int> ans;
    cout<<printSubseq(arr,0,2,ans,0,3);
    return 0;
}