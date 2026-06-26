class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        int l=0,r=0,sum=0,cnt=1e9;
        while(r<n){
            sum+=nums[r];
            while(sum>=target){
                cnt = min(r-l+1,cnt);
                sum-=nums[l];
                l++;
            }
            r++;
        }
        if(cnt == 1e9) return 0;
        return cnt;
    }
};