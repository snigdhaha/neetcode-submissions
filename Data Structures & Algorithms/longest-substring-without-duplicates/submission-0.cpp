class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
    
        int hashLen=256;

        int hash[hashLen];
        //initialize hash table with -1
        for(int i=0;i<hashLen;i++){
            hash[i]=-1;
        }

        int l=0,r=0,maxlen=0;
        
        while(r<n){
            if(hash[s[r]]!=-1){
                //move lfet point to right of last occurence of s[r]
                l=max(hash[s[r]]+1,l);
            }
            int len=r-l+1;
            maxlen=max(maxlen,len);

            hash[s[r]]=r;
            r++;
        }
        return maxlen;
    }
};
