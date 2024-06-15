class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        vector<int>mpp(26);;
        int l=0,r=0,maxf=0,maxlen=0;
        while(r<n)
        {
            mpp[s[r]-'A']++;
            maxf=max(maxf,mpp[s[r]-'A']);
            while((r-l+1-maxf)>k)
            {mpp[s[l]-'A']--;
            maxf=0;
            for(int i=0;i<26;i++)
            {
                maxf=max(maxf,mpp[i]);
            }
            l++;
            }
            if((r-l+1-maxf)<=k)
            {
                maxlen=max(maxlen,r-l+1);
            }
            r++;
        }
        return maxlen;
    }
};