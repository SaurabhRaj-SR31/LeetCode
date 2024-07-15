class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(auto &ch:s){
            if(st.empty()||ch=='('||ch=='{'||ch=='['){
                st.push(ch);
                continue;
            }
            else {
                if(ch==')'){
                    if(st.top()=='(')st.pop();
                else return false;
                }
                else   if(ch=='}'){
                 if(st.top()=='{')st.pop();
                else return false;}
                else {
                if(st.top()=='[')st.pop();
                else return false;
                } 
            }

        }
        return st.empty();
    }
};