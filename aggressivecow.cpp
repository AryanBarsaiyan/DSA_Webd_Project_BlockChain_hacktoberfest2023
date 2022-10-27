#include<bits/stdc++.h>
using namespace std;

bool isPossible(vector<int> &stalls, int k , int mid){
    int cowCount =1;
    int lstPos = stalls[0];
   for(int i = 0 ; i< stalls.size() ; i++){
       if(stalls[i]- lstPos >= mid){
           cowCount++;
           if(cowCount == k){
               return true;
           }
           lstPos = stalls[i];
       }
   }
    return false;
}

int aggressiveCows(vector<int> &stalls, int k)
{
    //    Write your code here.
    sort(stalls.begin() , stalls.end());
    int s =0;
    int n = stalls.size();
    int maxi = -1;
    for(int i = 0; i< n ; i++){
        maxi = max(maxi , stalls[i]);
    };
    int e =maxi;
    int ans =-1;
    int mid = s +(e-s)/2;
    
    while(s<=e){
        if(isPossible(stalls , k , mid)){
            ans = mid ; 
            s = mid + 1;
        }else{
            e = mid -1 ;
        }
        mid = s +(e-s)/2;
    }
    return ans;
}