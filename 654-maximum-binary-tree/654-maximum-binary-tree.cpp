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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        TreeNode* root=construct(nums,0,nums.size()-1);
        return root;
    }
    
    TreeNode* construct(vector<int>& nums, int s, int e){
        if(s>e) return NULL;
        if(s==e){
            return new TreeNode(nums[s]);
        }
        
        int index=findIndex(nums,s,e);
        TreeNode* root=new TreeNode(nums[index]);
        root->left=construct(nums,s,index-1);
        root->right=construct(nums,index+1,e);
        
        return root;
    }
    
    int findIndex(vector<int> nums,int s,int e){
        int maxi=INT_MIN;
        int index=-1;
        for(int i=s;i<=e;i++){
            if(nums[i]>maxi){
                maxi=nums[i];
                index=i;    
            }
        }
        
        return index;
    }
};