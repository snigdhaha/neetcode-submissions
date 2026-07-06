class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;

       for (auto &it : intervals){
            if (ans.empty() || ans.back()[1] < it[0]) {
                // No overlap
                ans.push_back(it);
            }
            else {
                // Overlap
                ans.back()[1] = max(ans.back()[1], it[1]);
            }
       }
       return ans;
    }
};
