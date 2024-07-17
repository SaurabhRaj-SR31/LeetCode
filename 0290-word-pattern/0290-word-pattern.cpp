class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<string,char>mp;
        set<char>st;
        int n=pattern.size();
        stringstream ss(s);
        string token;
        int count=0;
        vector<string>vec;

        while(ss>>token){
            count++;
            vec.push_back(token);

        }
        if(count!=n)return false;
        for(int i=0;i<n;i++){
            if(mp.find(vec[i])==mp.end()&&st.find(pattern[i])==st.end()){
                mp[vec[i]]=pattern[i];
                st.insert(pattern[i]);
            }
            else if(mp[vec[i]]!=pattern[i])return false;
        }
return true;
    }
};