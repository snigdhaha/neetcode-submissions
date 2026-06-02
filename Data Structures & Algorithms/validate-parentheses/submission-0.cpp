class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for(int it = 0; it < s.length(); it++) {
            if(s[it] == '(' || s[it] == '{' || s[it] == '[')
                st.push(s[it]);
            else {
                if(st.empty()) return false;

                char ch = st.top();
                st.pop();

                if((s[it] == ')' && ch == '(') ||
                   (s[it] == '}' && ch == '{') ||
                   (s[it] == ']' && ch == '['))
                    continue;
                else
                    return false;
            }
        }

        return st.empty();
    }
};