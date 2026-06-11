class Solution {
public:
    void helper(int index,int sum,vector<int>& arr,vector<int> ds,vector<vector<int>> &ans){
        if(sum==0){
            ans.push_back(ds);
            return;
        }

        for(int i=index;i<arr.size();i++){
            //skip dupes
            if(i>index && arr[i]==arr[i-1])continue;

            if(arr[i]>sum) break;

            ds.push_back(arr[i]);
            helper(i+1,sum-arr[i],arr,ds,ans);
            ds.pop_back();
        }

    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> ds;

        helper(0,target,candidates,ds,ans);
        return ans;
    }
};
