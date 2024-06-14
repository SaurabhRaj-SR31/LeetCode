class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int n=nums.size();
        int totl=0;
        sort(nums.begin(),nums.end());
        for(int i=1;i<n;i++)
        {if(nums[i]<=nums[i-1])
        {
            int incre=nums[i-1]-nums[i]+1;
            nums[i]+=incre;
            totl+=incre;
        }
            
            
        }
        return totl;
    }
};