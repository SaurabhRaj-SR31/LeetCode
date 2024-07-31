class Solution {
public:
int solve(int n,vector<int>&dp){
    if(n==0)return 0;

    int ans=INT_MAX;
if(dp[n]!=-1)return dp[n];
    for(int i=1;i<=sqrt(n);i++){
        int res=1+solve(n-i*i,dp);
        ans=min(res,ans);
    }
    return dp[n]=ans;
}
    int numSquares(int n) {
        vector<int>dp(10001,-1);
        return solve(n,dp);
    }
};