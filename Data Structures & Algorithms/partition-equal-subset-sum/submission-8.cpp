class Solution {
public:
    bool f(int ind,vector<int> &nums,int target,vector<vector<int>> &dp){
        if(target==0) return true;
        if(ind==0) return nums[ind]==target;

        if(dp[ind][target]!=-1) return dp[ind][target];

        bool notTake=0+f(ind-1,nums,target,dp);
        bool take=false;
        if(nums[ind]<=target){
            take=f(ind-1,nums,target-nums[ind],dp);
        }
        return dp[ind][target] = take || notTake;
    }

    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int s=0;
        for(int i=0;i<n;i++){
            s+=nums[i];
        }
        if(s%2!=0) return false;

        vector<vector<int>> dp(n,vector<int>((s/2)+1,-1));
        
        return f(n-1,nums,s/2,dp);
    }
};
