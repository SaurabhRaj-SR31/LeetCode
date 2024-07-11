class Solution {
public:
    string reverseParentheses(string s) {
        string res="";
        stack<int>st;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(')st.push(i);
            else if(s[i]==')'){
               int j = st.top();
                st.pop();
                reverse(s.begin() + j + 1, s.begin() + i);
            }
           
        } 
         
        for (char c : s) {
            if (c != '(' && c != ')') {
                res += c;
            }
        }
        return res;
    }
};