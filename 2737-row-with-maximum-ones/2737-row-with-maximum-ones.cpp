class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        
        int m=mat.size();
        int n=mat[0].size();
       if (mat.empty() || mat[0].empty()) {
            return {0, 0};
        }
        
        int maxcnt=0;
        int ind=0;
        int cnt=0;
        for(int i=0;i<m;i++)
        {sort(mat[i].begin(),mat[i].end());
            cnt=n-(lower_bound(mat[i].begin(),mat[i].end(),1)-mat[i].begin());
            if(cnt>maxcnt)
            {
                maxcnt=max(maxcnt,cnt);
                ind=i;
                
            }
        }
        if(ind==-1)return {0,0};
        return {ind,maxcnt};
    }
};