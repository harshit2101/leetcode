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
    
    TreeNode* solve(vector<int>& nums, int s, int e){
        if(s>e) return NULL;
        
        int mid=s+(e-s)/2;
        TreeNode* ans= new TreeNode(nums[mid]);
        
        ans->left=solve(nums,s,mid-1);
        ans->right=solve(nums,mid+1,e);
        
        return ans;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        
        if(nums.size()==0) return NULL;
        
        return solve(nums,0,nums.size()-1);
        // TreeNode* ans=new TreeNode();
        
        
    }
};