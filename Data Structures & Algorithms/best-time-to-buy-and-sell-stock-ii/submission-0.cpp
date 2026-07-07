class Solution {
public:
    int f(int i, int buy, vector<int>& prices, vector<vector<int>>& dp) {
        int n = prices.size();

        if (i == n) return 0;

        if (dp[i][buy] != -1)
            return dp[i][buy];

        if (buy == 0) {
            // Can buy or skip
            return dp[i][buy] = max(
                f(i + 1, 0, prices, dp),              // Skip
                -prices[i] + f(i + 1, 1, prices, dp) // Buy
            );
        }
        else {
            // Can sell or skip
            return dp[i][buy] = max(
                f(i + 1, 1, prices, dp),             // Skip
                prices[i] + f(i + 1, 0, prices, dp) // Sell
            );
        }
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));

        return f(0, 0, prices, dp);
    }
};