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
    
    int solve(TreeNode* root,int& ans, int direction){
        if(!root) return 0;
        
        if(root->left==NULL && root->right==NULL){
            if(direction==0) ans+=root->val;
        }
        
        solve(root->left,ans,0);
        solve(root->right,ans,1);
        return ans;
    }
    
    int sumOfLeftLeaves(TreeNode* root) {
        int ans=0;
        solve(root,ans,-1);
        
        return ans;
    }
};