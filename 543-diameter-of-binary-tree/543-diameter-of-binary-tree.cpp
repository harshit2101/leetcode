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
    int d=0;
    
    
    int getDiameter(TreeNode* root){
        if(!root)
            return 0;
        
        
        int leftD = getDiameter(root->left);
        int rightD = getDiameter(root->right);
        
        d = max(d,leftD+rightD);
        
        return 1 + max(leftD,rightD);
    }
    
    
    
    int diameterOfBinaryTree(TreeNode* root) {
        
        int temp = getDiameter(root);
        
        return d;
    }
};