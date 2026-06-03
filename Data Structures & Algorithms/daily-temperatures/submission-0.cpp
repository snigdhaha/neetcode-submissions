class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        vector<int> res(n);

        stack<int> st;
        for(int i=n-1;i>=0;i--){
            int currEl=temperatures[i];
            while(!st.empty() && temperatures[st.top()]<=currEl){
                st.pop();
            }
            res[i]=!st.empty()?st.top()-i:0;
            st.push(i);
        }
        return res;
    }
    
};
