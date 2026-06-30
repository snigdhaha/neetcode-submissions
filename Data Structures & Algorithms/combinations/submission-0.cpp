class Solution {
public:
    void f(int start,int n,int k,vector<vector<int>> &res,vector<int> &comb){
        if(comb.size()==k){
            res.push_back(comb);
            return;
        }

        for(int i= start;i<=n;i++){
            comb.push_back(i);
            f(i+1,n,k,res,comb);
            comb.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> comb;

        f(1,n,k,res,comb);

        return res;

    }
};