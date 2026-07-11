class Solution {
public:
    void solve(vector<int>& nums, int index, int xorr,int &ans) {
        if (index == nums.size()) {
            ans += xorr;
            return;
        }
        // Include nums[index]
        solve(nums, index + 1, xorr ^ nums[index],ans);

        // Exclude nums[index]
        solve(nums, index + 1, xorr,ans);
    }

    int subsetXORSum(vector<int>& nums) {
        int ans=0;
        int n=nums.size();
        solve(nums,0,0,ans);
        return ans;

    }
};