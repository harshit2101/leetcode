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
    
    int solve(TreeNode* root,int& maxSum){
        if(!root) return 0;
        
        int left=max(solve(root->left,maxSum),0);
        int right=max(solve(root->right,maxSum),0);
        
        maxSum=max(left+right+root->val,maxSum);
        
        return root->val+max(left,right);
    }
    
    int maxPathSum(TreeNode* root) {
        int maxSum=INT_MIN;
        solve(root,maxSum);
        return maxSum;
    }
};