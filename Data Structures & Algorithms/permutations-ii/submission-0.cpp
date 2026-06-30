class Solution {
public:
    void f(vector<int>& nums, vector<bool>& visited,vector<int>& perm, vector<vector<int>>& res){
        if (perm.size() == nums.size()) {
            res.push_back(perm);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            // Skip if already used
            if (visited[i])
                continue;
            // Skip duplicates
            if (i > 0 && nums[i] == nums[i - 1] && !visited[i - 1])
                continue;

            visited[i] = true;
            perm.push_back(nums[i]);
            f(nums, visited, perm, res);
            // Backtrack
            perm.pop_back();
            visited[i] = false;
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> res;
        vector<int> perm;
        vector<bool> visited(nums.size(), false);

        f(nums, visited, perm, res);

        return res;
    }
};