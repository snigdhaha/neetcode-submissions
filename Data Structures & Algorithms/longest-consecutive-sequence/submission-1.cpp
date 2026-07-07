class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int res=0;
        unordered_set<int> store(nums.begin(),nums.end());
        int longest=0;

        for(int num:nums){
            if(store.find(num-1)==store.end()){
                int length=1;
                while(store.find(num+length)!=store.end()){
                    length++;
                }
                longest = max(longest, length);

            }
        }
        return longest;
            
        
    }
};
