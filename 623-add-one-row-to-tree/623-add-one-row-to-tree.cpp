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
    
    void solve(TreeNode* root, int v, int d, int curd){
        
        if(root==NULL) return;
        
        if(curd==d-1){
            TreeNode* temp=root->left;
            root->left=new TreeNode(v);
            root->left->left=temp;
            
            temp=root->right;
            root->right=new TreeNode(v);
            root->right->right=temp;
        }
        
        else{
            solve(root->left,v,d, curd+1);
            solve(root->right,v,d, curd+1);
        }
    }
    
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        
        if(depth==1){
            TreeNode* node=new TreeNode(val);
            node->left=root;
            return node;
        }
        
        solve(root,val,depth,1);
        return root;
    }
};