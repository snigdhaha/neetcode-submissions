class Solution {
public:
    bool f(int ind, int weight, vector<int>& stones, vector<vector<int>>& dp) {
        if (weight == 0)
            return true;

        if (ind == 0)
            return stones[0] == weight;

        if (dp[ind][weight] != -1)
            return dp[ind][weight];

        bool notTake = f(ind - 1, weight, stones, dp);

        bool take = false;
        if (stones[ind] <= weight)
            take = f(ind - 1, weight - stones[ind], stones, dp);

        return dp[ind][weight] = take || notTake;
    }

    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();

        int sum = 0;
        for (int x : stones)
            sum += x;

        vector<vector<int>> dp(n, vector<int>(sum + 1, -1));

        int ans = INT_MAX;

        for (int s1 = 0; s1 <= sum / 2; s1++) {
            if (f(n - 1, s1, stones, dp))
                ans = min(ans, sum - 2 * s1);
        }

        return ans;
    }
};