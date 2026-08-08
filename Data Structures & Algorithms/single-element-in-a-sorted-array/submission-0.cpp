class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;

        while (l <= r) {
            int m = l + (r - l) / 2;
            if ((m - 1 < 0 || nums[m - 1] != nums[m]) &&
                (m + 1 == nums.size() || nums[m] != nums[m + 1])) {
                return nums[m];
            }

            int leftSize = (m - 1 >= 0 && nums[m - 1] == nums[m]) ? m - 1 : m;
            if (leftSize % 2 == 1) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }

        return -1;
    }
};