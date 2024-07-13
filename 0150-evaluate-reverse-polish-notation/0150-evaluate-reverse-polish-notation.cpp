class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        int res=0;
         unordered_map<string, function<int(int, int)>> mp = {
            {"+", [](int a, int b) { return a + b; }},
            {"-", [](int a, int b) { return a - b; }},
            {"*", [](int a, int b) { return a * b; }},
            {"/", [](int a, int b) { return a / b; }}
        };

         for (auto &t : tokens) {
            if (t == "+" || t == "-" || t == "*" || t == "/") {
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();
                st.push(mp[t](a, b));
            } else {
                st.push(stoi(t));
            }
        }
        return st.top();

        
    }

};