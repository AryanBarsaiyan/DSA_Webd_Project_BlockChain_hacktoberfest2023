#include<bits/stdc++.h>
using namespace std;

bool printSubseq(int arr[] , int sum , int val ,vector<int> &ans , int index , int size){

    if(index >= size){
        if(val == sum){
            for(auto it : ans)
                cout<<it<<" ";
            return true;
        }
        return false;
    }

    //including
    ans.push_back(arr[index]);
    if(printSubseq(arr, sum+arr[index], val ,ans, index+1, size) == true)
        return true;

    //not including
    ans.pop_back();
    if(printSubseq(arr, sum, val , ans, index+1, size) == true)
        return true;
    return false;
}

int main(){
    int arr[] = {1,2,1};
    vector<int> ans;
    printSubseq(arr,0,2,ans,0,3);
    return 0;
}