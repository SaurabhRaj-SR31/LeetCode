class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int cnt=0;
        int n=strs.size();
        int k=strs[0].size();
        for(int i=0;i<k;i++)
        {
            for(int j=1;j<n;j++)
            {
                if(strs[j][i]<strs[j-1][i])
                {cnt++;break;}


            }
        }
        return cnt;
    }
};