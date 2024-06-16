class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long long coverLimit = 1; // Start with a coverage limit of 1
        int patchesCount = 0; // Initialize the count of patches needed
        size_t idx = 0; // Initialize the current index for the nums vector

        // Loop until the coverage limit exceeds n
        while (coverLimit <= n) {
            // Check if the current index is within bounds and the current number is within the coverage limit
            if (idx < nums.size() && nums[idx] <= coverLimit) {
                // The current number can extend the coverage limit
                coverLimit += nums[idx++]; // Extend the coverage range and move to the next number
            } else {
                // The current coverage limit cannot be extended with the existing numbers
                ++patchesCount; // Increment the number of patches
                coverLimit <<= 1; // Double the coverage limit
            }
        }

        // Return the number of patches needed to cover the range [1, n]
        return patchesCount;
    }
};