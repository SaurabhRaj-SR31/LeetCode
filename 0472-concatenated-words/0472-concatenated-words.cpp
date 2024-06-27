class Solution {
public:
     unordered_map<string,bool>mpp;
    bool isconcstenated(string word, unordered_set<string>&st){
        int n=word.size();if(mpp.find(word)!=mpp.end())return mpp[word];

        for(int i=0;i<n;i++)
        {
            string prefix=word.substr(0,i+1);
            string suffix=word.substr(i+1);
            if((st.find(prefix)!=st.end()&&st.find(suffix)!=st.end())||(st.find(prefix)!=st.end()&& isconcstenated(suffix,st) ))return mpp[word]=true;
        }
        return mpp[word]=false;
    }
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        int n=words.size();
        vector<string>ans;
        unordered_set<string>st(begin(words),end(words));
        for(auto &w:words)
        {
            if(isconcstenated(w,st)){
                ans.push_back(w);
            }
        }
        return ans;
    }
};