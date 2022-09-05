/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        
        vector<vector<int>> res;
        
        if(!root) return res;
        
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty()){
            int n = q.size();
            vector<int> vals; 
            
            for(int i=0;i<n;i++){
                Node* cur = q.front();
                q.pop();
                
                vals.push_back(cur->val);
                
                for(int j=0;j<cur->children.size();j++){
                    q.push(cur->children[j]);
                }
            }
            res.push_back(vals);
        }
        return res;
    }
};