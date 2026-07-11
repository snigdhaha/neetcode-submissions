class Solution {
public:
    bool solve(int index, vector<int>& matchsticks, vector<int>& sides, int target) {
        // All matchsticks have been used
        if (index == matchsticks.size()) {
            return true;
        }

        for (int i = 0; i < 4; i++) {
                                                               
            // If this stick doesn't fit on this side
            if (sides[i] + matchsticks[index] > target)
                continue;

            // Place the stick
            sides[i] += matchsticks[index];

            if (solve(index + 1, matchsticks, sides, target))
                return true;

            // Backtrack
            sides[i] -= matchsticks[index];
        }

        return false;
    }

    bool makesquare(vector<int>& matchsticks) {
        int sum = 0;
        for (int x : matchsticks)
            sum += x;

        if (sum % 4 != 0)
            return false;

        int target = sum / 4;

        // Sort in descending order for faster pruning
        sort(matchsticks.begin(), matchsticks.end(), greater<int>());

        // Largest stick cannot be longer than one side
        if (matchsticks[0] > target)
            return false;

        vector<int> sides(4, 0);

        return solve(0, matchsticks, sides, target);
    }
};