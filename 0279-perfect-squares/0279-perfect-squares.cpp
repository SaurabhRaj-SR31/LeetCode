class Solution {
public:
// int helper (int n){
//     if(n==0)return 0;
// int ans=INT_MAX;

//     for(int i=1;i<=sqrt(n);i++){
//         int res=1+helper(n-i*i);
//         ans=min(res,ans);
//     }
//     return ans;
// }
    int numSquares(int n) {
           vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;

        // Fill the dp array iteratively.
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j * j <= i; ++j) {
                dp[i] = min(dp[i], dp[i - j * j] + 1);
            }
        }

        return dp[n];}
};