class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int l=0,r=0;
        int n1=word1.size();
        int n2=word2.size();

        string ans="";

        while(l<n1 && r<n2){
            ans+=word1[l];
            ans+=word2[r];
            l++;r++;
        }
        ans+=word1.substr(l);
        ans+=word2.substr(r);
        return ans;
    }
};