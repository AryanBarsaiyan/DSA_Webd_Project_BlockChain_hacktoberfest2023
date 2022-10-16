class Solution {
public:
    int maxEqualFreq(vector<int>& nums) {
         vector<int> count(100001,0),fre(100001,0);
        int maxcnt=0,ans=0;
        for(int i=0;i<nums.size();++i){
            int num=nums[i];
            ++count[num];
            ++fre[count[num]];
            maxcnt=max(maxcnt,count[num]);
	   
            if((fre[maxcnt]==1&&maxcnt+(fre[maxcnt-1]-1)*(maxcnt-1)==i+1)||(fre[maxcnt]*maxcnt+1==i+1))
                ans=i+1;
        }
        if(maxcnt==1) 
            return nums.size();
        return ans;
    }
};
