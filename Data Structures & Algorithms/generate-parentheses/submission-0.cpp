class Solution {
public:
    void helper(string curr, int open,int close,int n,vector<string> &res){
        if(curr.size()==2*n){
            res.push_back(curr);
            return;
        }

        if(open<n) helper(curr+'(',open+1,close,n,res);
        if(close<open) helper(curr+')',open,close+1,n,res);

    }

    vector<string> generateParenthesis(int n) {
        vector<string> res;
        helper("",0,0,n,res);
        return res;
    }
};
