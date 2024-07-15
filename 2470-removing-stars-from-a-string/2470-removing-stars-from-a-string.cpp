class Solution {
public:
    string removeStars(string s) {
       int i = 0;
        for(char c : s) {
            c != '*' ? s[i++] = c : --i;
        }
        return s.substr(0, i);
    }
};