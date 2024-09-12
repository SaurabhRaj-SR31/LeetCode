class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
         set<char> st(allowed.begin(), allowed.end());
         int cnt=0;
         for(auto  &str:words){
            bool yes=true;
            for(auto &ch:str){
                if(st.find(ch)==st.end()){
                    yes=false;
                    break;
                }
            }
if(yes)cnt++;
         }
         return cnt;
    }
};