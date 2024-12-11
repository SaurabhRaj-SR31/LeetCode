class Solution {
public:
    int maximumLength(string s) {
        int n=s.size();
        map<pair<char,int>,int>mp;
        for(int i=0;i<n;i++){
            char ch=s[i];
            int l=0;
            for(int j=i;j<n;j++){
                if(ch==s[j]){
                    l++;
                    mp[{ch,l}]++;
                }
                else break;
            }
        }
        int res=0;
        for(auto &it:mp){
            int len=it.first.second;
            int freq=it.second;
            if(freq>=3 && len>res)res=len;

        }
        return res==0?-1:res;
    }
};