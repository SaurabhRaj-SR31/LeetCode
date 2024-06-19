class Solution {
public:
    string reverseWords(string s) {
        int n=s.size();
        stringstream ss(s);
        string token="";
        string res="";

        while(ss>>token){
            if (res.empty()) {
                res = token;
            } else {
                res = token + " " + res;
            }
        }
        return res;
    }
};