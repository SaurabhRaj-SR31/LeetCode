class Solution {
public:
    bool f(int ind ,int n,int target ,vector<vector<bool>> &dp,vector<int>& nums)
{
    
     for(int i=0;i<n;i++) dp[i][0]=true;
     if(nums[0]<=target)dp[0][nums[0]]=true;
     for(int i=1;i<n;i++){
        for(int t=1;t<=target;t++)
        {
            bool nottake=dp[i-1][t];
            bool take=false;
            if(nums[i]<=t)take=dp[i-1][t-nums[i]];
            dp[i][t]=nottake|take;
        }
     }
return dp[n-1][target];
}
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int totsum=0;
        
        for(int i=0;i<n;i++)
        {
            totsum+=nums[i];
        }
        if(totsum%2)return false;
        int tar=totsum/2;
    vector<vector<bool>> dp(n,vector<bool>(tar+1,0));
        return f(n,n,tar,dp,nums);




    }
};