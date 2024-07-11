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
public:int mini=INT_MAX;
void printInorder(TreeNode* node,TreeNode* &prev)
{
    if (node == NULL)
        return;

   
    printInorder(node->left,prev);

  if(prev!=NULL){
    mini=min(abs(node->val-prev->val),mini);
  }
  prev=node;

    
    printInorder(node->right,prev);
}
    int getMinimumDifference(TreeNode* root) {
        TreeNode* prev=NULL;
    printInorder(root,prev);
    return mini;
    }
};