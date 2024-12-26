class Solution {
public:
   int diffsubset(int n,vector<int>& nums, int target)
{
    vector<int>prev(target+1,0);
    vector<int>cur(target+1,0);
    if(nums[0]==0)prev[0]=2;
    else prev[0]=1;
    if(nums[0]!=0 && nums[0]<=target)prev[nums[0]]=1;
    for(int i=1;i<n;i++)
    {
        for(int tar=0;tar<=target;tar++)
        {
            int notake=prev[tar];
            int take=0;
            if( nums[i]<=tar)take=prev[tar-nums[i]];
            cur[tar]=(notake+take);
        }
        prev=cur;

    }
    return prev[target];

}
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int totsum=0;
        for (int i=0;i<n;i++)
        {
        totsum+=nums[i];
        }
        if((totsum-target)<0 || (totsum-target)%2 != 0) return 0;
        int key=(totsum-target)/2;
        return diffsubset(n,nums,key);

    }
};