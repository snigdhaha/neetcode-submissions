class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n= nums.size();
        int res = nums[0];
        int currMin=1,currMax=1;

        for(int num:nums){
            int tmp = currMax*num;
            currMax = max(num,max(tmp,num*currMin));
            currMin = min(num,min(tmp,num*currMin));
            res=max(res,currMax);
        }
        return res;
    }
};
