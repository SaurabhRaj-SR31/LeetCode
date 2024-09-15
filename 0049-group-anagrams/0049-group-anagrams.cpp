class Solution {
public:
string generate(string &word){
    int arr[26]={0};
    string res;
    for(auto &ch:word){
        arr[ch-'a']++;
    }
    for(int i=0;i<26;i++){
        if(arr[i]>0)
        res+=string(arr[i],i+'a');
    }
    return res;
}
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>res;
        int n=strs.size();
        unordered_map<string,vector<string>>mp;
        for(int i=0;i<n;i++){
            string word =strs[i];
            string temp=generate(word);
            mp[temp].push_back(word);
        }
        for(auto &i:mp){
            res.push_back(i.second);
        }
        return res;
    }
};