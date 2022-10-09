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
    
    void inorder(TreeNode* root, vector<int>& traversal){
        if(!root) return;
        
        inorder(root->left, traversal);
        traversal.push_back(root->val);
        inorder(root->right, traversal);
        
    }
    
    bool findTarget(TreeNode* root, int k) {
        
        vector<int> traversal;
        
        inorder(root,traversal);
        
        int left=0, right=traversal.size()-1;
        
        while(left<right){
            if(traversal[left]+traversal[right]==k) return true;
            else if(traversal[left]+traversal[right]<k) left++;
            else right--;
        }
        
        return false;
    }
};