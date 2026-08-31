class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n=nums.size();
        int min_ele_idx=min_element(begin(nums),end(nums))-begin(nums);
        int max_ele_idx=max_element(begin(nums),end(nums))-begin(nums);
        int left=min(min_ele_idx,max_ele_idx);
        int right=max(min_ele_idx,max_ele_idx);
        return min({right+1,left+1+n-right,n-left});
    }
};