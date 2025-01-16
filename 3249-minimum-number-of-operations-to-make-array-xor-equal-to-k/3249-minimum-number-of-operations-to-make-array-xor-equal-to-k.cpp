class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n=nums.size();
        auto x = 0;
        for (auto &num:nums){
            x^=num;
        }
        return __builtin_popcount(k^x);
    }
};