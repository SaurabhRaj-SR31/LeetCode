class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> minelement(n,0);
        int mini=INT_MAX;
         int maxi=INT_MIN;
        for(int i=n-1;i>=0;i--){
            mini=min(mini,nums[i]);
            minelement[i]=mini;
        }
        for(int i=0;i<n;i++){
            maxi=max(maxi,nums[i]);
            mini=minelement[i];
            if(maxi-mini<=k)return i;
        }
        return -1;
    }
};