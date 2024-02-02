class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        int prev=nums[0];
        int prev2=0;
        int cur;
        for(int i=1;i<n;i++)
        {
            int take=nums[i];if(i>1)take+=prev2;
            int nottake=0+prev;
            cur=max(take,nottake);
            prev2=prev;
            prev=cur;
        }
        return prev;
    }
};