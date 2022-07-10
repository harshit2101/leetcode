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
    int kthSmallest(TreeNode* root, int k) {
        TreeNode* cur = root;
        
        int ans, count = 1;
        
        while (cur) {
            
            if ( !cur->left ) {
                if (count == k) ans = cur->val;
                cur = cur->right;
                ++count;
                
            } else {
                TreeNode* tmp = cur->left;
				
                // Going to the right most element of left Subtree.
                while (tmp->right && tmp->right != cur)
                    tmp = tmp->right;
                
                if ( tmp->right ) {
                    tmp->right = nullptr;
                    if (count == k) ans = cur->val;
                    cur = cur->right;
                    ++count;
                    
                } else {
                    tmp->right = cur;
                    cur = cur->left;
                }
            }
        }
        return ans;
    }
};