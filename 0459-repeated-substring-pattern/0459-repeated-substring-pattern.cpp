class Solution {
public:
    bool repeatedSubstringPattern(string s) {
       int n = s.size();
        
        for(int l = n / 2; l >= 1; l--) {
            if(n % l == 0) {
                string res = "";
                int times = n / l;
                string temp = s.substr(0, l);
                while(times--) {
                    res += temp;
                }
                if(s == res) {
                    return true;
                }
            }
        }
        
        return false;
         
    }
};