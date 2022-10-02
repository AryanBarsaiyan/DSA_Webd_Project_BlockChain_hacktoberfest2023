class Solution {
    public int[] twoSum(int[] nums, int target) {
        int res[]=new int[2]; //returning array
        int flag=0;
        for(int i=0;i<nums.length;i++){
            int j=i+1;
            while(j<nums.length){
                if(nums[i]+nums[j]==target){ //if elements found
                    res[0]=i;
                    res[1]=j;
                    flag++;
                    break;
                }
                else j++;
            }
            if(flag==1)
                break;
        }
        return res;
        
    }
}
