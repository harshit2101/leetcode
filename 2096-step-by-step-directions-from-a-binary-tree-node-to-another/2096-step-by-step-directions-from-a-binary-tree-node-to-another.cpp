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
    string nodepath;
    TreeNode* LCA(TreeNode* root, int x, int y){
        if(!root)
            return NULL;
        if(root->val == x or root->val == y)
            return root;
        TreeNode* left_lca = LCA(root->left, x, y);
        TreeNode* right_lca = LCA(root->right, x, y);
        
        if(left_lca and right_lca)
            return root;
        
        return (left_lca != NULL) ? left_lca : right_lca;
    }
    
    void TracePath(TreeNode* root, int x, string& path){
        if(!root)
            return;
        if(root->val == x){
            nodepath = path;
            return;
        }
        path += "L";
        TracePath(root->left, x, path);
        path.pop_back();
        path += "R";
        TracePath(root->right, x, path);
        path.pop_back();
    }
    
    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode* lca = LCA(root, startValue, destValue);
        
        string temp = "", startPath, endPath;
        TracePath(lca, startValue, temp);
        startPath = nodepath;
        
        temp = "";
        TracePath(lca, destValue, temp);
        endPath = nodepath;
        
        string str(startPath.length(), 'U');
        return str+endPath;
    }
};