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
    
    void solve(TreeNode* root, int target,vector<vector<int>>& ans,vector<int>& temp,int sum){
        if(!root) return;
        
        sum+=root->val;
        temp.push_back(root->val);
        if(sum==target && !root->left && !root->right){
            ans.push_back(temp);
        }
        
        solve(root->left,target,ans,temp,sum);
        solve(root->right,target,ans,temp,sum);
        temp.pop_back();
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(root,targetSum,ans,temp,0);
        return ans;
    }
};