class Solution {
public:
int mod=1e9+7;
    int countHomogenous(string s) {
        int n=s.size();
        int len=0,res=0;

        for(int i=0;i<n;i++)
        {
            if(i>0 && s[i]==s[i-1])
            {
                len+=1;

            }
            else{
                len=1;
            }
             res = (res + len) % mod;
        }
        return res;
    }
};