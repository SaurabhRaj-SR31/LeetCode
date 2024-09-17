class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        vector<string> ans;
        unordered_map<string, int> count;
        istringstream iss(s1 + ' ' + s2); // Concatenate s1 and s2

        string word;
        while (iss >> word)  // Extract words from the concatenated string
            ++count[word];   // Count the occurrences of each word

        for (const auto& [word, freq] : count)
            if (freq == 1)   // If the word occurs only once, it's uncommon
                ans.push_back(word);

        return ans;
    }
};
