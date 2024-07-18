class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int res=0;
        unordered_map<int,int>mpp;
        for(auto &i:nums){
            res+=mpp[i];
            mpp[i]++;
        }
        return res;
    }
};