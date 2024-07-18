class Solution {
public:
    int minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {
        int i=0;int j=0;
        int hor=1;
        int ver=1;
        int res=0;
        sort(begin(horizontalCut),end(horizontalCut),greater<int>());
        sort(begin(verticalCut),end(verticalCut),greater<int>());
        while(i<m-1 && j<n-1){
            if(verticalCut[j]>=horizontalCut[i]){
                res+=verticalCut[j]*hor;
                ver++;j++;
            }
            else{
                res+=horizontalCut[i]*ver;
                hor++;
                i++;
            }
        }
        while(i<m-1){
             res+=horizontalCut[i]*ver;
                hor++;
                i++;
        }
        while(j<n-1){
             res+=verticalCut[j]*hor;
                ver++;j++;
        }
        return res;

    }
};