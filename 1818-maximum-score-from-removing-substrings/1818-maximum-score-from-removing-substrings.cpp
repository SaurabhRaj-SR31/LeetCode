class Solution {
public:
   string removesubstr(string &s, string &match) {
        int i = 0;
        for (int j = 0; j < s.size(); j++) {
            s[i] = s[j];
            i++;
            if (i >= 2 && s[i-1] == match[1] && s[i-2] == match[0]) {
                i -= 2;
            }
        }
        s.erase(begin(s) + i, end(s));
        return s;
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