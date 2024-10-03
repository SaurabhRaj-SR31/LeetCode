class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n=nums.size();
        int sum=0;
        for(auto &i:nums){
            sum=(sum+i)%p;
        }
        int target=sum%p;
        if(target==0)return 0;
        int res=n;
        int cur=0;
        unordered_map<int,int>mp;
        mp[0]=-1;
        for(int j=0;j<n;j++){
            cur=(cur+nums[j])%p;
            int prev=(cur-target+p)%p;
            if(mp.find(prev)!=mp.end()){
                res=min(res,j-mp[prev]);
            }
            mp[cur]=j;
        }
        return res==n?-1:res;
    }
};