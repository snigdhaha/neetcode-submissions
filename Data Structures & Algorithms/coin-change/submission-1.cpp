class Solution {
public:
    int f(int ind,int amt, vector<int> &coins){
        if(amt==0) return 0;
        if(amt<0) return 1e9;
        
        if (ind == 0) {
            if (amt%coins[0]==0) return amt/coins[0];
            return 1e9;   
        }

        int notTake = f(ind-1,amt,coins);
        int take = 1e9;
        if(coins[ind]<=amt) take=1+f(ind,amt-coins[ind],coins);

        return min(take,notTake);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        if(amount==0) return 0;
        int ans = f(n-1,amount,coins);

        if(ans==1e9) return -1;
        return ans;
    }
};
