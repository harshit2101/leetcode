class Solution {
public:
    
    
    void dfs(vector<int> adj[], vector<int>& vis, int source){
        
        vis[source]=1;
        
        for(auto it:adj[source]){
            if(!vis[it]){
                dfs(adj,vis,it);
            }
        }
    }
    
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int> adj[n];
        vector<int> vis(n+1,0);
        
        for(auto e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        
        dfs(adj,vis,source);
        
        return vis[destination];
    }
};