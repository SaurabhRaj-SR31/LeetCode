class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        if (m != n) return false;

        std::vector<int> f1(26, 0);
        std::vector<int> f2(26, 0);
        std::vector<int> p1(26, 0);
        std::vector<int> p2(26, 0);

        // Calculate frequency of each character
        for (char c : word1) {
            f1[c - 'a']++;
            p1[c - 'a'] = 1; // Mark presence
        }
        for (char c : word2) {
            f2[c - 'a']++;
            p2[c - 'a'] = 1; // Mark presence
        }

        // Check if both words have the same unique characters
        for (int i = 0; i < 26; ++i) {
            if (p1[i] != p2[i]) return false;
        }

        // Sort frequency vectors
        std::sort(f1.begin(), f1.end());
        std::sort(f2.begin(), f2.end());

        // Compare sorted frequency vectors
        return f1 == f2;

            }
};