class Solution {
public:
    int lengthOfLastWord(string s) {
       int idx = s.find_last_not_of(' ');
        if (idx == string::npos) {
            return 0; // No non-space characters found
        }
        
        s.erase(idx + 1);

        // Find the last space in the trimmed string
        int lspace_idx = s.find_last_of(' ');
        return lspace_idx == string::npos ? s.size() : s.size() - lspace_idx - 1;
    }
};