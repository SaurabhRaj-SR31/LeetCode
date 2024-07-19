class Solution {
public:int rev(int num){
    int ans=0;
    while(num>0){
        int remainder=num%10;
        ans=(ans*10)+remainder;
        num=num/10;
    }
    return ans;
}
int m=1e9+7;
 int numIdenticalPairs(vector<int>& nums) {
        int res=0;
        unordered_map<int,int>mpp;
        for(auto &i:nums){
            res=(res+mpp[i])%m;
            mpp[i]++;
        }
        return res;
    }
    int countNicePairs(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            nums[i]=nums[i]-rev(nums[i]);
        }
return numIdenticalPairs(nums);
    }
};