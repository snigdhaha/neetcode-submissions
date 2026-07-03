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

        vector<vector<int>> dp(n,vector<int>((s/2)+1,0));
        
        //return f(n-1,nums,s/2,dp);
        for(int i=0;i<n;i++){
            dp[i][0]=1;
        }

        for(int ind=1;ind<n;ind++){
            for(int target=0;target<=s/2;target++){
                if(ind==0 && nums[ind]==target) dp[ind][target]=1;
                bool notTake=0+dp[ind-1][target];
                bool take=false;
                if(nums[ind]<=target){
                    take=dp[ind-1][target-nums[ind]];
                }
                dp[ind][target] = take || notTake;
            }
        }
        return dp[n-1][s/2];
    }
};
