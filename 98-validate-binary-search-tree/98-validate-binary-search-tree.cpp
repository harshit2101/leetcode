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
    
    void inorder(TreeNode* root ,vector<int> & TT ){
        if(!root){
            return;
        }
        
        inorder(root->left,TT);
        
        TT.push_back(root->val);
        
        inorder(root->right,TT);
        
    }
    
    bool isValidBST(TreeNode* root) {
        
        vector<int> TT;
        
        inorder(root, TT);
        
        
        for(int i=1; i< TT.size();i++){
            if(TT[i]<=TT[i-1]){
                //not valid
                return false;
            }
        }
        
        return true;
    }
};