class MinStack {
public:
    stack<int> st;
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        stack<int> temp;
        int mini=st.top();
        while(st.size()){
            mini=min(st.top(),mini);
            temp.push(st.top());
            st.pop();
        }
        while (temp.size()) {
            st.push(temp.top());
            temp.pop();
        }
        return mini;
    }
};
