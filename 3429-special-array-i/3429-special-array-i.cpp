class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        int n=nums.size();
        vector<int>cumsum(n,0);
       
        for(int i=1;i<n;i++){
            if(nums[i]%2 == nums[i-1]%2)
             cumsum[i]=cumsum[i-1]+1;
             else{
                 cumsum[i]=cumsum[i-1];
             }
        }
        
        return ((cumsum[n-1]-cumsum[0])==0)?true:false;
    }
};