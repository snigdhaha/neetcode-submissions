class Solution {
public:
    void swap(int i,int j, vector<int>& nums){
        int temp=0;
        temp=nums[i];
        nums[i]=nums[j];
        nums[j]=temp;

        return;
    }

    void helper(int index,vector<int>& nums,vector<vector<int>> &ans){
        if(index==nums.size()){
            vector<int> ds;
            for(int i=0;i<nums.size();i++){
                ds.push_back(nums[i]);
            }
            ans.push_back(ds);
            return;
        }

        for(int i=index;i<nums.size();i++){
            swap(i,index,nums);
            helper(index+1,nums,ans);
            swap(i,index,nums);
        }

    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        helper(0,nums,ans);
        return ans;
    }
};
