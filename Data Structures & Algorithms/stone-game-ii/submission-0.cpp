class Solution {
public:
    int n;

    int f(int i, int M, int turn,vector<int>& piles,vector<vector<vector<int>>>& dp) {

        if (i >= n)
            return 0;

        if (dp[i][M][turn] != -1)
            return dp[i][M][turn];

        int stones = 0;

        if (turn) { // Alice-turn=1
            int ans = 0;
            for (int X = 1; X <= 2 * M && i + X <= n; X++) {
                stones += piles[i + X - 1];
                ans = max(ans, stones +f(i + X, max(M, X), 0, piles, dp));
            }
            return dp[i][M][turn] = ans;
        }
        else { // Bob
            int ans = INT_MAX;

            for (int X = 1; X <= 2 * M && i + X <= n; X++) {
                ans = min(ans, f(i + X, max(M, X), 1, piles, dp));
            }

            return dp[i][M][turn] = ans;
        }
    }

    int stoneGameII(vector<int>& piles) {

        n = piles.size();

        vector<vector<vector<int>>> dp(
            n,
            vector<vector<int>>(n + 1,
                vector<int>(2, -1)));

        return f(0, 1, 1, piles, dp);
    }
};