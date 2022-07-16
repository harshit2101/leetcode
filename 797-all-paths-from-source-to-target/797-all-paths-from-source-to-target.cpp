class Solution {
public:
    
    void solve(vector<vector<int>>& graph, vector<vector<int>>& ans,vector<int>& temp,int node){
        temp.push_back(node);
        
        if(node==graph.size()-1) ans.push_back(temp);
        else{
            for(auto it: graph[node]){
                solve(graph,ans,temp,it);
            }
        }
        temp.pop_back();
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(graph,ans,temp,0);
        return ans;
    }
};