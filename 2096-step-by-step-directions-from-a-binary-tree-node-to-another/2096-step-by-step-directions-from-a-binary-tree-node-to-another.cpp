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
    int lca(TreeNode* node, int p, int q, TreeNode*& ca){
        if(!node)
            return 0;
        int left = 0;
        int right = 0;
        int self = (node->val == p || node->val == q)?1:0;
        left = lca(node->left, p, q, ca);
        right = lca(node->right, p, q, ca);
        if(left+right+self==2 && ca==NULL)
            ca = node;
        return left+right+self;
    }
    
    bool solve(TreeNode* node, string& ans, int val, int mode){
        if(!node)
            return false;
        
        if(node->val == val)
            return true;
        if(mode == 1)
            ans.push_back('U');
        else
            ans.push_back('L');
        if(solve(node->left, ans, val, mode))
            return true;
        ans.pop_back();
        if(mode == 1)
            ans.push_back('U');
        else
            ans.push_back('R');
        if(solve(node->right, ans, val, mode))
            return true;
        ans.pop_back();
        return false;
    }

    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode* ca = NULL;
        lca(root, startValue, destValue, ca);
       
        string ans = "";
        solve(ca, ans, startValue, 1);
       
        solve(ca, ans, destValue, 2);
      
        return ans;
    }
};