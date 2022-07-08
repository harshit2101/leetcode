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
     void getSum(TreeNode*root,unordered_map<int,int>&values,long currentSum,int &targetSum, int&path)
    {
        if(root==NULL)
        {
            return;
        }
        currentSum+=root->val;
        if(currentSum==targetSum)
        {
            path++;
        }
        if(values.find(currentSum-targetSum)!=values.end())
        {
            path+=values[currentSum-targetSum];
        }
        values[currentSum]+=1;
        getSum(root->left,values,currentSum,targetSum,path);
        getSum(root->right,values,currentSum,targetSum,path);
        values[currentSum]-=1;
        return;
    }
public:
    int pathSum(TreeNode* root, int targetSum) 
    {
        unordered_map<int,int> values;
        int path=0;
        long curSum =0;
        getSum(root,values,curSum,targetSum,path);
        return path;
    }
};