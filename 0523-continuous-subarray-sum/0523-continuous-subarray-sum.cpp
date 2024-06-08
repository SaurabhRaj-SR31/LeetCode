class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mpp;
        mpp[0] = -1;
        int presum = 0;
        for (int i = 0; i < n; i++) {
            presum += nums[i];
            int remove = presum % k;
            if (remove < 0) remove += k;  // Handle negative remainders
            if (mpp.count(remove)) {
                if (i - mpp[remove] > 1) return true;
            } else {
                mpp[remove] = i;
            }
        }
        return false;
    }
};
