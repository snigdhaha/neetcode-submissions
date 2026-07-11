class Solution {
public:
    bool solve(int index, vector<int>& nums, vector<int>& subsets, int target) {

        if (index == nums.size())
            return true;

        for (int i = 0; i < subsets.size(); i++) {

            if (subsets[i] + nums[index] > target)
                continue;

            subsets[i] += nums[index];

            if (solve(index + 1, nums, subsets, target))
                return true;

            subsets[i] -= nums[index];

            // Optimization
            if (subsets[i] == 0)
                break;
        }

        return false;
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {

        int sum = 0;
        for (int x : nums)
            sum += x;

        if (sum % k != 0)
            return false;

        int target = sum / k;

        sort(nums.begin(), nums.end(), greater<int>());

        if (nums[0] > target)
            return false;

        vector<int> subsets(k, 0);

        return solve(0, nums, subsets, target);
    }
};