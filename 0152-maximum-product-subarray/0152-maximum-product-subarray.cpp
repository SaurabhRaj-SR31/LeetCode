class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int preffix=1;int suffix=1;
        int ans=INT_MIN;
        for(int i=0;i<n;i++)
        {
            if(preffix==0)preffix=1;
             if(suffix==0)suffix=1;
            preffix=preffix*nums[i];
            suffix=suffix*nums[n-i-1];
            ans=max(ans,max(preffix,suffix));
            
            
        }
        return ans;
        
    }
};