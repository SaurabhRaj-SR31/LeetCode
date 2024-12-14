class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int rangeMin = INT_MAX;
        int rangeMax = INT_MIN;

        long long count = 0;
        long long winSize;
        int right;

        for (right = 0; right < n; ++right) {
            rangeMin = min(rangeMin, nums[right]);
            rangeMax = max(rangeMax, nums[right]);

            if (rangeMax - rangeMin > 2) {
                winSize = right - left;
                count += (winSize * (winSize + 1)) / 2;

                left = right;
                // Expand current window to as left as possible
                rangeMin = nums[right];
                rangeMax = nums[right];
                while (left > 0 && abs(nums[right] - nums[left - 1]) <= 2) {
                    left--;
                    rangeMin = min(rangeMin, nums[left]);
                    rangeMax = max(rangeMax, nums[left]);
                }
                // Subtract overcounted subarrays
                if (left < right) {
                    winSize = right - left;
                    count -= (winSize * (winSize + 1)) / 2;
                }
            }
        }
        // Add subarrays from the last window
        winSize = right - left;
        count += (winSize * (winSize + 1)) / 2;

        return count;
    }
};
