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
    
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(!root)
            return NULL;
        if(depth==1)
        {
            TreeNode*temp=new TreeNode(val);
            temp->left=root;
            return temp;
        }
        if(depth==2)
        {
            if(root->left)
            {
                TreeNode*l=new TreeNode(val);
                l->left=root->left;
                root->left=l;
            }
            else
            {
                TreeNode*l=new TreeNode(val);
                root->left=l;
            }
            if(root->right)
            {
                TreeNode*r=new TreeNode(val);
                r->right=root->right;
                root->right=r;
            }
            else
            {
                TreeNode*r=new TreeNode(val);
                root->right=r;
            }
            return root;
        }
        root->left=addOneRow(root->left,val,depth-1);
        root->right=addOneRow(root->right,val,depth-1);
        return root;
    }
};