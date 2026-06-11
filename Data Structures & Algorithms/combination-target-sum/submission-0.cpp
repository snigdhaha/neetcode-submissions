class Solution {
public:
    void helper(int index,vector<int>& nums,int sum,vector<int> ds,vector<vector<int>> &ans){
        if(index==nums.size()){
            if(sum==0){
                ans.push_back(ds);
                
            }
            return; 
        }

        if(nums[index]<=sum){
            ds.push_back(nums[index]);
            helper(index,nums,sum-nums[index],ds,ans);
            ds.pop_back();
        }

        helper(index+1,nums,sum,ds,ans);

    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> ds;
        vector<vector<int>> ans;

        helper(0,nums,target,ds,ans);
        return ans;
    }
};
