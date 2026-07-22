class Solution {
public:
    vector<int> dp;   // -1 = not computed, 0 = false, 1 = true
    int n;

    bool f(int i, string &s, int minJump, int maxJump) {

        if (i == n - 1)
            return true;

        if (dp[i] != -1)
            return dp[i];

        for (int jump = minJump; jump <= maxJump; jump++) {

            int next = i + jump;

            if (next >= n)
                break;

            if (s[next] == '0') {
                if (f(next, s, minJump, maxJump))
                    return dp[i] = true;
            }
        }

        return dp[i] = false;
    }

    bool canReach(string s, int minJump, int maxJump) {

        n = s.size();

        if (s[n - 1] == '1')
            return false;

        dp.assign(n, -1);

        return f(0, s, minJump, maxJump);
    }
};