# Longest Increasing Subsequence

### Problem Statement
-Given an integer array nums, return the length of the longest strictly increasing subsequence. A subsequence is a sequence that can be derived from an array by deleting some or no elements without changing the order of the remaining elements. For example, [3,6,2,7] is a subsequence of the array [0,3,1,6,2,2,7].

### Constraints :
![image](https://user-images.githubusercontent.com/76700307/193437670-50d74979-e72b-4cf2-b93e-491e4488b717.png)

### Example 1:
![image](https://user-images.githubusercontent.com/76700307/193437681-88285e71-d4e7-4207-9503-bd4c1d77b616.png)

### Example 2:
![image](https://user-images.githubusercontent.com/76700307/193437698-6cf6a396-b02a-4851-984f-f2981147c293.png)

### Code for LIS using memoization :
```
#include <bits/stdc++.h>
using namespace std;

int getAns(int arr[], int n,  int ind, int prev_index, vector<vector<int>>& dp){
    
    // base condition
    if(ind == n)
        return 0;
        
    if(dp[ind][prev_index+1]!=-1)
        return dp[ind][prev_index+1];
    
    int notTake = 0 + getAns(arr,n,ind+1,prev_index,dp);
    
    int take = 0;
    
    if(prev_index == -1 || arr[ind] > arr[prev_index]){
        take = 1 + getAns(arr,n,ind+1,ind,dp);
    }
    
    return dp[ind][prev_index+1] = max(notTake,take);
}


int longestIncreasingSubsequence(int arr[], int n){
    
    vector<vector<int>> dp(n,vector<int>(n+1,-1));
    
    return getAns(arr,n,0,-1,dp);
}

int main() {
	
	int arr[] = {10,9,2,5,3,7,101,18};
	
	int n = sizeof(arr)/sizeof(arr[0]);
	
	cout<<"The length of the longest increasing subsequence is "
        <<longestIncreasingSubsequence(arr,n);
	
	return 0;
}
```

### Code for given question using Binary Search : 
```
#include <bits/stdc++.h>
using namespace std;

int getAns(int arr[], int n,  int ind, int prev_index, vector<vector<int>>& dp){
    
    // base condition
    if(ind == n)
        return 0;
        
    if(dp[ind][prev_index+1]!=-1)
        return dp[ind][prev_index+1];
    
    int notTake = 0 + getAns(arr,n,ind+1,prev_index,dp);
    
    int take = 0;
    
    if(prev_index == -1 || arr[ind] > arr[prev_index]){
        take = 1 + getAns(arr,n,ind+1,ind,dp);
    }
    
    return dp[ind][prev_index+1] = max(notTake,take);
}


int longestIncreasingSubsequence(int arr[], int n){
    
    vector<int> temp;
    temp.push_back(arr[0]);
    
    int len = 1;
    
    for(int i=1; i<n; i++){
        if(arr[i]>temp.back()){
           // arr[i] > the last element of temp array 
           
           temp.push_back(arr[i]);
           len++;
           
        } 
        else{
	// replacement step
            int ind = lower_bound(temp.begin(),temp.end(),arr[i]) - temp.begin();
            temp[ind] = arr[i];
        }
        
    }
    
    return len;
}
    

int main() {
	
	int arr[] = {10,9,2,5,3,7,101,18};
	
	int n = sizeof(arr)/sizeof(arr[0]);
	
	cout<<"The length of the longest increasing subsequence is "
        <<longestIncreasingSubsequence(arr,n);
	
	return 0;
}
```

That's all from my side. Thanks for reading.
