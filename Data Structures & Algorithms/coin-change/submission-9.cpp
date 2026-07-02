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

        vector<vector<int>> dp(n,vector<int>(amount+1,1e9));

        // int ans = f(n-1,amount,coins,dp);

        // if(ans==1e9) return -1;
        // return ans;

        for(int i=0;i<n;i++){
            dp[i][0]=0;
        }

        for(int amt=0;amt<=amount;amt++){
                if (amt%coins[0]==0) dp[0][amt]=amt/coins[0];
                else dp[0][amt]=1e9;
        }

        for(int ind=1;ind<n;ind++){
            for(int amt=1;amt<=amount;amt++){
                int notTake = dp[ind-1][amt];
                int take = 1e9;
                if(coins[ind]<=amt) take=1+dp[ind][amt-coins[ind]];
                dp[ind][amt] = min(take, notTake);
            }
        }

        return (dp[n-1][amount]>=1e9)? -1 : dp[n-1][amount];
    }
};
