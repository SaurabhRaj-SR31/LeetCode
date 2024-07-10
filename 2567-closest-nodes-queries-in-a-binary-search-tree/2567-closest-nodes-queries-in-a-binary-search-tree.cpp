/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
vector<int>temp;
   int ceil(vector<int>&nums,int target) {
  int lb = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        if (lb == nums.size()) {
            return -1;
        }
        return nums[lb];
    }

    int floor(vector<int>&arr,int x) {
      
        int n=arr.size();
       int low = 0, high = n - 1;
    int ans = -1;

    while (low <= high) {
        int mid = low +(high-low) / 2;
        // maybe an answer
        	if (arr[mid] <= x) {
			ans = arr[mid];
			//look for smaller index on the left
			low = mid + 1;
		}
		else {
			high = mid - 1; // look on the right
		}
    }
    return ans;
    }

void printInorder(TreeNode* node)
{
    if (node == NULL)
        return;

    // First recur on left child
    printInorder(node->left);

    // Then print the data of node
   temp.push_back(node->val);

    // Now recur on right child
    printInorder(node->right);
}
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        vector<vector<int>> ans;
        printInorder(root);
        for (auto& query : queries) {
            vector<int> ceil_floor(2, -1);
            ceil_floor[0] = floor(temp, query);
            ceil_floor[1] = ceil(temp, query);
            ans.push_back(ceil_floor);
        }
        return ans;
    }
};