#include<bits/stdc++.h>
using namespace std;

void printSubseq(int arr[] , vector<int> &ans , int index , int size){

    if(index >= size){
        for(auto it : ans)
            cout<<it<<" ";
        if(ans.size() == 0)
            cout<<"{}";
        cout<<endl;
        return;
    }

    //including
    ans.push_back(arr[index]);
    printSubseq(arr, ans, index+1, size);

    //not including
    ans.pop_back();
    printSubseq(arr, ans, index+1, size);
}

int main(){
    int arr[] = {3,1,2};
    vector<int> ans;
    printSubseq(arr,ans,0,3);
    return 0;
}