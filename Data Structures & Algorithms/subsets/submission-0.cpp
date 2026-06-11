class Solution {
public:
    void helper(int index,vector<int>& nums,vector<int> curr,vector<vector<int>> &result){
        if(index==nums.size()){
            result.push_back(curr);
            return;
        }

        //exclude
        helper(index+1,nums,curr,result);

        //incude
        curr.push_back(nums[index]);
        helper(index+1,nums,curr,result);
        curr.pop_back();
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<int> curr;

        vector<vector<int>> result;

        helper(0,nums,curr,result);

        return result;

    }
};
