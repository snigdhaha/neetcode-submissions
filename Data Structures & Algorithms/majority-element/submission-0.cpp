class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        int el=0;
        int cnt=0;
        int i=0;
        while(i<n){
            if(cnt==0){
                cnt=1;
                el=nums[i];
            }
            else if(nums[i]==el) cnt++;
            else cnt--;
            i++;
        }
        return el;
    }
};