class Solution {
public:
    bool canJump(vector<int>& nums) {
        int reachable=0;
        
        int n=nums.size();
        if(n==1 && nums[0]>0)return true;
        for(int i=0;i<n;i++)
        {
            if(reachable<i)return false;
            reachable=max(reachable,i+nums[i]);
        }
        return true;
    }
};