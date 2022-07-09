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
    
    void findIndex(vector<int>in,map<int,int>& m){
        for(int i=0;i<in.size();i++){
            m[in[i]]=i;
        }
    }
    
    TreeNode* solve(vector<int> pre, vector<int> in,int inStart,int inEnd,int& p_index,int n,map<int,int>& m){
        if(p_index>=n || inStart>inEnd){
            return NULL;
        }
        int element=pre[p_index++];
        TreeNode* root=new TreeNode(element);
        int pos=m[element];
        
        root->left=solve(pre,in,inStart,pos-1,p_index,n,m);
        root->right=solve(pre,in,pos+1,inEnd,p_index,n,m);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int p_index=0;
        int n=inorder.size();
        map<int,int> m;
        findIndex(inorder,m);
        TreeNode* ans=solve(preorder,inorder,0,n-1,p_index,n,m);
        return ans;
    }
};