class Solution {
public:unordered_map<string,bool>mp;
bool solve(string s1, string s2){
    if(s1==s2)return true;

    if(s1.size()!=s2.size())return false;

    bool res=false;
    int n=s1.size();

    string key=s1+"_"+s2;

if(mp.find(key)!=mp.end())return mp[key];
    for(int i=1;i<n;i++){
         
                bool swapped=solve(s1.substr(i,n-i),s2.substr(0,n-i))&&solve(s1.substr(0,i),s2.substr(n-i,i));
                if(swapped){
                    res=true;
                    break;
                }

         bool notswapped=solve(s1.substr(0,i),s2.substr(0,i))&&solve(s1.substr(i,n-i),s2.substr(i,n-i));
          if(notswapped){
                    res=true;
                    break;
                }
    }
    return mp[key]=res;

}
    bool isScramble(string s1, string s2) {
        return solve(s1,s2);
    }
};