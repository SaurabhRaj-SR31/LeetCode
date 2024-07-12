class Solution {
public:
   string removesubstr(string &s, string &match) {
        stack<char>st;
        for(auto &ch:s){
            if (ch==match[1] && !st.empty() && st.top()==match[0]){
                st.pop();

            }
            else{
                st.push(ch);
            }}
            string str;
            while(!st.empty()){
                str.push_back(st.top());
                st.pop();

            }
           
        
         reverse(begin(str),end(str));
            return str;
    }

    int maximumGain(string s, int x, int y) {
        int n = s.size();
        int score = 0;
         string maxstr = (x > y) ? "ab" : "ba";
        string minstr = (x < y) ? "ab" : "ba";
        
        string firstpass = removesubstr(s, maxstr);
        int l=firstpass.size();
        int charremoved = n - firstpass.size();


        score += (charremoved / 2) * max(x, y);
        
        string second = removesubstr(firstpass, minstr);
        charremoved = l - second.size();
        score += (charremoved / 2) * min(x, y);
        
        return score;
    }
};