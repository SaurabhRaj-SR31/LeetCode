class Solution {
public:
    int minimumDeletions(string s) {
        int n=s.size();
        int ans=INT_MAX;
        int cnt_A=0;
        int cnt_B=0;

        for(int i=0;i<n;i++){
            if(s[i]=='a')
             cnt_A++;

        }
        for(int i=0;i<n;i++){
            if(s[i]=='a')cnt_A--;
            ans=min(ans,cnt_A+cnt_B);
            if(s[i]=='b')cnt_B++;



        }
        return ans;

    }
};