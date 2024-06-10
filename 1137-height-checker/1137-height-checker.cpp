class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int n=heights.size();
        int cnt=0;

        vector<int> exp(n);
        for(int i=0;i<n;i++)
        {
            exp[i]=heights[i];
        }
        sort(exp.begin(),exp.end());
        for(int i=0;i<n;i++)
        {
           if( exp[i]^heights[i])cnt++;
        }

return cnt;
    }
};