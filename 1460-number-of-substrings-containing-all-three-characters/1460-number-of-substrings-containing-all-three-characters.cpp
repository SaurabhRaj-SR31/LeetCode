class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.size();
        int cnt=0;
        vector<int>hash(3,-1);
        for(int i=0;i<n;i++)
        {
            hash[s[i]-'a']=i;
            cnt+=1+min(hash[0],min(hash[1],hash[2]));
        }
        return cnt;
    }
};