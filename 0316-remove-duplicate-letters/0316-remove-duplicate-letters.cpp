class Solution {
public:
    string removeDuplicateLetters(string s) {
        string res;
        int n=s.size();
        vector<int>lastind(26);
        vector<bool>taken(26,false);
        for(int i=0;i<n;i++){
            lastind[s[i]-'a']=i;
        }
        
          for(int i=0;i<n;i++){
            if(taken[s[i]-'a']==true)continue;
            while(res.size()>0 && res.back()> s[i] && lastind[ res.back()-'a']>i){
                taken[ res.back()-'a']=false;
                res.pop_back();
            }
            res.push_back(s[i]);
            taken[s[i]-'a']=true;
        }
        return res;
    }
};