class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        unordered_map<int,int>hash;

        for(int i=0;i<n;i++){
            hash[nums[i]]=i;
        }

        for(int i=0;i<n;i++){
            int diff=target-nums[i];
            if(hash.find(diff) != hash.end() && hash[diff]!=i){
                return {i,hash[diff]};
            }
        }
        return {};
    }
};
