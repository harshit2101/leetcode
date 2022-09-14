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
    
    void solve(TreeNode* root, vector<int>& v, int& count){
        if(root==NULL) return;
        
        v[root->val]++;
        solve(root->left,v,count);
        solve(root->right,v,count);
        
        if(!root->left && !root->right){
            int flag=0;
            for(int i=1;i<=9;i++){
                if(v[i]%2!=0) flag++;
            }
            if(flag==0 || flag==1) count++;
        }
        v[root->val]--;
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        
        vector<int> v(10,0);
        int count=0;
        solve(root,v,count);
        
        return count;
    }
};