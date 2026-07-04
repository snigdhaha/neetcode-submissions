class Solution {
public:
    int f(int ind,int amt,vector<int>&nums){
        if(ind==0){
            int ways = 0;
            if(amt == nums[0]) ways++;
            if(amt == -nums[0]) ways++;
            return ways;
        }      
        
        int add=f(ind-1,amt-nums[ind],nums);
        int subtract=f(ind-1,amt+nums[ind],nums);
        
        return add+subtract;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        return f(n-1,target,nums);
    }
};
