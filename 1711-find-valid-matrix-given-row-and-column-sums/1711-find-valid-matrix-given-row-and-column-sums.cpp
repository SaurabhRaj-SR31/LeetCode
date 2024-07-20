class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int n=rowSum.size();
        int m=colSum.size();
         vector<vector<int>>arr(n,vector<int>(m,0));
         int i=0;int j=0;
         while(i<n&& j<m){
            arr[i][j]=min(colSum[j],rowSum[i]);
            rowSum[i]-=arr[i][j];
            colSum[j]-=arr[i][j];
            if(rowSum[i]==0)i++;
            if( colSum[j]==0)j++;
         }
return arr;
    }
};