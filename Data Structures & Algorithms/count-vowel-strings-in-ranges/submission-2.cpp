class Solution {
public:
    bool isValid(string s){
        char first = s[0];
        char last = s[s.size() - 1];

        if ((first == 'a' || first == 'e' || first == 'i' || first == 'o' || first == 'u') && (last  == 'a' || last  == 'e' || last  == 'i' || last  == 'o' || last  == 'u'))
        return true;

    return false;
    }

    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> ans(queries.size());

        for(int i=0;i<queries.size();i++){
            int l=queries[i][0];
            int r=queries[i][1];
            int cnt=0;
            for(int j=l;j<=r;j++){
                if(isValid(words[j])){
                    cnt++;
                }
            }
            ans[i]=cnt;
        }
        return ans;
    }
};