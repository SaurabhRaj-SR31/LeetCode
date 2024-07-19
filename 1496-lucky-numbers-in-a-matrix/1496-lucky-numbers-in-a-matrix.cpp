class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
       

        int rowminmax=INT_MIN;
        for(int r=0;r<n;r++){
            int minele=INT_MAX;
            for(int c=0;c<m;c++){
                minele=min(minele,matrix[r][c]);
            }
            rowminmax=max(minele,rowminmax);
        }
        int colmaxmin=INT_MAX;
         for(int c=0;c<m;c++){
            int maxele=INT_MIN;
            for(int r=0;r<n;r++){
                maxele=max(maxele,matrix[r][c]);
            }
            colmaxmin=min(maxele,colmaxmin);
        }
        if(colmaxmin==rowminmax)return {rowminmax};
        return {};

    }
};