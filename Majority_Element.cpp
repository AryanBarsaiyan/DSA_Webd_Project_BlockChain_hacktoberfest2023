#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        int n = nums.size()/2;
        unordered_map<int,int>mpp;
        for(int i=0;i<nums.size();i++)
        {
            mpp[nums[i]]++;
        }
        for(int i=0;i<nums.size();i++)
        {
            if(mpp[nums[i]]>n){
                return nums[i];
            }
        }
        return nums[0];
    }
};

int main()
{
    int n;
    cin>>n;
    vector<int> nums;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        nums.push_back(x);
    }
    Solution ob;
    int res = ob.majorityElement(nums);
    cout<<res<<endl;

}