class Solution {
public:
    string reverseWords(string s) {
        int n=s.size();
        stringstream ss(s);
        string token="";
        string res="";

        while(ss>>token){
            reverse(begin(token),end(token));
            
                res =res+  token +" ";
            
        }
        res.pop_back();
        return res;
    }
};