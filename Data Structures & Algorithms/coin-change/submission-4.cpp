class Solution {
public:
    int f(int ind,int amt, vector<int> &coins,vector<vector<int>> &dp){
        if(amt==0) return 0;
        if(amt<0) return 1e9;
        
        if (ind == 0) {
            if (amt%coins[0]==0) return amt/coins[0];
            return 1e9;   
        }

        if(dp[ind][amt]!=-1) return dp[ind][amt];

        int notTake = f(ind-1,amt,coins,dp);
        int take = 1e9;
        if(coins[ind]<=amt) take=1+f(ind,amt-coins[ind],coins,dp);

        return dp[ind][amt] = min(take,notTake);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        if(amount==0) return 0;

        vector<vector<int>> dp(n,vector<int>(amount+1,-1));

        int ans = f(n-1,amount,coins,dp);

        if(ans==1e9) return -1;
        return ans;
    }
};
