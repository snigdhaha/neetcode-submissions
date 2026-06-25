class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        unordered_map<int,int> hash(n);
        vector<int> res;

        for(int num : nums){
            hash[num]++;
        }

        for (auto &p : hash){
            if(p.second > nums.size()/3) res.push_back(p.first);
        }
        return res;
        
    }
};