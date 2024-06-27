class Solution {
public:
    void computeLPS(string &pat, vector<int>& lps) {
        int len = 0;
        int i = 1;
        lps[0] = 0;
        while (i < pat.size()) {
            if (pat[i] == pat[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
    }

    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();
        if (m == 0) return 0;
        
        vector<int> lps(m, 0);
        computeLPS(needle, lps);
        
        int i = 0; // index for haystack
        int j = 0; // index for needle
        
        while (i < n) {
            if (needle[j] == haystack[i]) {
                i++;
                j++;
            }

            if (j == m) {
                return i - j;
            } else if (i < n && needle[j] != haystack[i]) {
                if (j != 0) {
                    j = lps[j - 1];
                } else {
                    i++;
                }
            }
        }
        
        return -1; // pattern not found
    }
};