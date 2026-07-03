class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=0;
        int maxSum=INT_MIN;

        for(auto num:nums){
            sum+=num;
            maxSum=max(maxSum,sum);

            if(sum<0) sum=0;
        }

        return maxSum;
    }
};
