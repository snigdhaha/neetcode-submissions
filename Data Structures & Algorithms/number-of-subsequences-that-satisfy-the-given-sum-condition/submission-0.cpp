class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        const int MOD = 1e9 + 7;
        int n = nums.size();

        sort(nums.begin(), nums.end());

        // Precompute powers of 2
        vector<int> power(n);
        power[0] = 1;
        for (int i = 1; i < n; i++) {
            power[i] = (2LL * power[i - 1]) % MOD;
        }

        int i=0;
        int j=n-1;
        int cnt=0;

        while(i<=j){
            if(nums[j]+nums[i]<=target){
                cnt=(cnt + power[j - i]) % MOD;
                i++;
            }
            else j--;
            
        }
        return cnt;
    }
};