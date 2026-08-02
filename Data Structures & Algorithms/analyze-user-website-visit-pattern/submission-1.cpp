class Solution {
public:
    vector<string> mostVisitedPattern(vector<string>& username, vector<int>& timestamp, vector<string>& website) {
        vector<tuple<int, string, string>> visits;

        int n=username.size();
        for(int i=0;i<n;i++){
            visits.push_back({timestamp[i], username[i], website[i]});
        }

        sort(visits.begin(),visits.end());

        unordered_map<string, vector<string>> history;

        for(auto &[time,user,site]: visits){
            history[user].push_back(site);
        }

        // Pattern -> number of users having this pattern
        map<vector<string>, int> count;

        // Process each user
        for (auto &[user, sites] : history) {

            set<vector<string>> seen;   // avoid duplicate patterns for same user

            int m = sites.size();

            // Generate all 3-length subsequences
            for (int i = 0; i < m; i++) {
                for (int j = i + 1; j < m; j++) {
                    for (int k = j + 1; k < m; k++) {

                        vector<string> pattern = {
                            sites[i],
                            sites[j],
                            sites[k]
                        };

                        seen.insert(pattern);
                    }
                }
            }

            // Count each pattern once per user
            for (auto &pattern : seen) {
                count[pattern]++;
            }
        }

        vector<string> ans;
        int best = 0;

        // map iterates in lexicographical order
        for (auto &[pattern, freq] : count) {

            if (freq > best) {
                best = freq;
                ans = pattern;
            }
        }

        return ans;
    }
};