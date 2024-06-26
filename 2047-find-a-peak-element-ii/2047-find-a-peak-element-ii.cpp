class Solution {
public:
    int maxelm(vector<vector<int>>& mat,int col ){
        int n=mat.size();
        int m=mat[0].size();
        int ind=-1;
        int maxi=-1;
        for(int i=0;i<n;i++)
        {
            if(mat[i][col]>maxi)
            {
                maxi=mat[i][col];
                ind=i;
            }
        }
return ind;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        int l=0;
        int h=m-1;

        while(l<=h)
        {
            int mid=l+(h-l)/2;
            int row=maxelm(mat,mid);
            int left=mid-1>=0?mat[row][mid-1]:-1;
            int right=mid+1<m?mat[row][mid+1]:-1;
            if(mat[row][mid]>left && mat[row][mid]>right){
                return {row,mid};
            }
            else if(mat[row][mid]<left )h=mid-1;
            else l=mid+1;


        }
        return {-1,-1};
    }
};