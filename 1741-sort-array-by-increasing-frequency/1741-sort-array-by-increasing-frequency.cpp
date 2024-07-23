class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
         vector<int>ans;
         unordered_map<int,int>mpp;
         for(auto &num:nums){
            mpp[num]++;
         }
         auto lambda=[&](int &n1,int &n2){
            if(mpp[n1]==mpp[n2])return n1>n2;
            return mpp[n1]<mpp[n2];
         };
         sort(begin(nums),end(nums),lambda); 
return nums;
    }
};