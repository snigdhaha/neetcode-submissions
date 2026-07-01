class Solution {
public:
    int f(int ind,string s,vector<int> &dp){
        int  n = s.size();
        if(ind==n) return 1;
        if(s[ind]=='0') return 0;

        if(dp[ind]!=-1) return dp[ind];

        int ways = f(ind+1,s,dp);

        if(ind+1<n){
            int nums = (s[ind]-'0')*10 + (s[ind+1]-'0');
            if(nums<=26){
                ways+=f(ind+2,s,dp);
            }
        }
        return dp[ind]= ways;
    }

    int numDecodings(string s) {
        int  n =s.size();
        vector<int> dp(n,-1);
        return f(0,s,dp);
    }
};
