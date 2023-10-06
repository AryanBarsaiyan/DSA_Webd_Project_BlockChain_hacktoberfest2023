// https://leetcode.com/problems/find-peak-element/

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n= nums.size();
        int s=0;
        int e=n-1;
        int mid=(s+e)/2;
        while(s<e){
            if(nums[mid]<nums[mid+1]){
                s=s+1;
            }
            if(nums[mid]>nums[mid+1]){
                e=mid;
            }
            mid=(s+e)/2;
        }
        return mid ;
    }
};