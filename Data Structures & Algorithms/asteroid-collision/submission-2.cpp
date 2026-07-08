class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;

        for (int a : asteroids) {

            if (a > 0) {
                st.push(a);
            }
            else {

                while (!st.empty() && st.top() > 0 && st.top() < abs(a)) {
                    st.pop();
                }

                if (!st.empty() && st.top() == abs(a)) {
                    st.pop();
                }
                else if (st.empty() || st.top() < 0) {
                    st.push(a);
                }
                // else:
                // top > abs(a)
                // current asteroid is destroyed
            }
        }

        vector<int> ans;

        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};