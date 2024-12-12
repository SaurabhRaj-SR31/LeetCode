class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
         int n=nums.size();
         int m=queries.size();
            vector<int>cumsum(n,0);
       
        for(int i=1;i<n;i++){
            if(nums[i]%2 == nums[i-1]%2)
             cumsum[i]=cumsum[i-1]+1;
             else{
                 cumsum[i]=cumsum[i-1];
             }
        }
        vector<bool>res(m,false);
        int i=0;
        for(auto &num:queries){
            int start=num[0];
            int end=num[1];
            if ((cumsum[end]-cumsum[start])==0){
                res[i]=true;
            }
            i++;

        }
        return res;
    }
};