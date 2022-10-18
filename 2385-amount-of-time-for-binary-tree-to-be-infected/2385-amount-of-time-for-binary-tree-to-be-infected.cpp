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
    
    int solve(map<TreeNode*, TreeNode*> parent, TreeNode* target){
        unordered_map<TreeNode*,bool> vis;
        vis[target]=true;
        
        queue<TreeNode*> q;
        q.push(target);
        
        int time=0;
        
        while(!q.empty()){
            int size=q.size();
            int flag=0;
            
            for(int i=0;i<size;i++){
                TreeNode* current=q.front();
                q.pop();
                vis[current]=true;
                
                if(current->left && !vis[current->left]){
                    flag=1;
                    q.push(current->left);
                    vis[current->left]=true;
                }
                
                if(current->right && !vis[current->right]){
                    flag=1;
                    q.push(current->right);
                    vis[current->right]=true;
                }
                
                if(parent[current] && !vis[parent[current]]){
                    flag=1;
                    q.push(parent[current]);
                    vis[parent[current]]=true;
                }
            }
            
            if(flag) time++;
        }
        
        return time;
    }
    
    TreeNode* makeParent(TreeNode* root,map<TreeNode*, TreeNode*>& parent, int start){
        TreeNode* target;
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();
            
            if(node->val==start) target=node;
            
            if(node->left){
                parent[node->left]=node;
                q.push(node->left);
            }
            
            if(node->right){
                parent[node->right]=node;
                q.push(node->right);
            }
        }
        return target;
    }
    
    int amountOfTime(TreeNode* root, int start) {
        map<TreeNode*, TreeNode*> parent;
        TreeNode* target= makeParent(root, parent, start);
        int ans= solve(parent, target);
        return ans;
    }
};