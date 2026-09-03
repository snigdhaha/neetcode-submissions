class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> freq;
        int left = 0, right = 0;
        int maxCount = 0;
        int maxLength = 0;
        while (right < s.size()){
            freq[s[right]]++;

            maxCount = max(maxCount, freq[s[right]]);

            //invalid case
            if((right-left+1)-maxCount >k){   //len-maxfreq>k
                freq[s[left]]--;
                left++;
            }

            maxLength=max(maxLength,right-left+1);
            right++;
        }
        return maxLength;
    }
};
