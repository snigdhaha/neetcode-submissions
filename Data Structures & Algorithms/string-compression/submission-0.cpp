class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size(); 
        int i = 0; 
        int j = 0; 
        while (i < n) { 
            char ch = chars[i]; 
            int start = i; 
            while (i < n && chars[i] == ch) i++; 
            int count = i - start; 
            chars[j++] = ch; 
            if (count > 1) { 
                string s = to_string(count); 
                for (char c : s) chars[j++] = c; 
            } 
        } 
        return j;
        
    }
};