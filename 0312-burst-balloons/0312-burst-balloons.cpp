class Solution {
public:
    int maxCoins(vector<int>& cuts) {
         int c=cuts.size();
        cuts.push_back(1);
        cuts.insert(cuts.begin(),1);
       
        
      
        vector<vector<int>>dp(c+2,vector<int>(c+2,0));
        for(int i=c;i>=1;i--)
        {
            for(int j=1;j<=c;j++)
            {  int maxi=INT_MIN;
            if(i>j)continue;
                for(int ind=i;ind<=j;ind++)
                {
                    int cost=cuts[j+1]*cuts[i-1]*cuts[ind]+dp[i][ind-1]+dp[ind+1][j];
                maxi=max(maxi,cost);
                }
            dp[i][j]=maxi;
            }
        }
        return dp[1][c];
    }
};