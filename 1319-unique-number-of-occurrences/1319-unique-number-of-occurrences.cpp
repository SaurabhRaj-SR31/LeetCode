class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int>mp;
        for(auto &x:arr){
            mp[x]++;

        }
        set<int>st;
        for(auto&i:mp){
            if(st.find(i.second)!=st.end()){
                return false;
            }
            st.insert(i.second);
        }
        return true;
    }
};