class Solution {
public:

    bool isOperator(string s){
        return s=="+" || s=="-" || s=="*" || s=="/";
    }



    int evalRPN(vector<string>& tokens) {
        
        stack<string> st;
        int n=tokens.size();
        for(int i=0;i<n;i++){
            if(!isOperator(tokens[i])){
                st.push(tokens[i]);
            }
            else{
                int num2=stoi(st.top());
                st.pop();
                int num1=stoi(st.top());
                st.pop();
                
                int ans;

                if(tokens[i]=="+"){
                    ans=num1+num2;
                }
                else if(tokens[i]=="*"){
                    ans=num1*num2;
                }
                else if(tokens[i]=="-"){
                    ans=num1-num2;
                }
                else {
                    ans=num1/num2;
                }
                st.push(to_string(ans));
            }
            
        }
        return stoi(st.top());
    }
};
