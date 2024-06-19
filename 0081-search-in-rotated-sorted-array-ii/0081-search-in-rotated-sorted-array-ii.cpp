class Solution {
public:
    bool search(vector<int>& nums, int target) {
          int low = 0;
        int high = nums.size() - 1;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target) return true;
            if (nums[low] == nums[mid] &&  nums[mid]==nums[high])

            {
                low+=1;
                high-=1;
                continue;
            }
            
            if (nums[low] <= nums[mid]) { // Check if the left half is sorted
                if (nums[low] <= target && target < nums[mid]) { // Target is in the left half
                    high = mid - 1;
                } else { // Target is in the right half
                    low = mid + 1;
                }
            } else { // Right half is sorted
                if (nums[mid] < target && target <= nums[high]) { // Target is in the right half
                    low = mid + 1;
                } else { // Target is in the left half
                    high = mid - 1;
                }
            }
        }
        
        return false; // Target not found
    }
};