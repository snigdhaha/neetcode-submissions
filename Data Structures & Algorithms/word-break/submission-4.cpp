class Solution {
public:
    bool f(int ind,string &s,unordered_set<string> &st,vector<int> &dp){
        int n=s.size();

        if(ind == n) return true;

        if(dp[ind] != -1)
            return dp[ind];

        string temp="";
        for(int i=ind;i<n;i++){
            temp+=s[i];

            if(st.count(temp)){
                if(f(i+1,s,st,dp)) return dp[ind] = true;
            }
        }
        return dp[ind] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st(wordDict.begin(),wordDict.end());
        vector<int> dp(s.size(),-1);
        return f(0,s,st,dp);
    }
};
