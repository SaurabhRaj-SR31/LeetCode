class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        int lsum=0,rsum=0,maxsum=0;
        int rindx=n-1;
        for(int i=0;i<k;i++)
        {
        lsum+=cardPoints[i];
        }
        maxsum=lsum;
        for(int i=k-1;i>=0;i--)
        {
            lsum-=cardPoints[i];
            rsum+=cardPoints[rindx--];
            maxsum=max(lsum+rsum,maxsum);
        }
        return maxsum;
    }
};