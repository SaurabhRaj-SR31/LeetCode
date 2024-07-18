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
   void makegraph(TreeNode* root,TreeNode* prev,unordered_map<TreeNode*,vector<TreeNode*>>&adj, unordered_set<TreeNode*>&st){
    if(root==NULL)return;
    if(root->left==NULL && root->right==NULL)st.insert(root);
    if(prev!=NULL){
        adj[prev].push_back(root);
        adj[root].push_back(prev);

    }
    makegraph(root->left,root,adj,st);
    makegraph(root->right,root,adj,st);

   }
    int countPairs(TreeNode* root, int distance) {
        int cnt=0;
        unordered_map<TreeNode*,vector<TreeNode*>>adj;
        unordered_set<TreeNode*>st;
        makegraph(root,NULL,adj,st);
    for(auto &leaf:st){
        unordered_set<TreeNode*>visited;
        queue<TreeNode*>q;
        q.push(leaf);
        visited.insert(leaf);
        for(int lvl=0;lvl<=distance;lvl++){
            int size=q.size();
            while(size--){
                TreeNode* curr=q.front();
                q.pop();
                if(curr!=leaf && st.count(curr))cnt++;
                for(auto &nghbr:adj[curr]){
                    if(!visited.count(nghbr)){
                        q.push(nghbr);
                        visited.insert(nghbr);
                    }
                }
            }
        }

    }
        
return cnt/2;
    }
};