class Solution {
public:
    
    void dfs(int x,vector<int>& vis,vector<vector<int>>& adj){
        vis[x]=true;
        for(auto i : adj[x]){
            if(!vis[i])
                dfs(i,vis,adj);
        }
    }
    
    int makeConnected(int n, vector<vector<int>>& conn) {
        if(conn.size() < n-1)
            return -1;
       vector<vector<int>>adj(n);
        vector<int> vis(n,false);
        for(int i=0; i<conn.size(); i++){
            adj[conn[i][0]].push_back(conn[i][1]);
            adj[conn[i][1]].push_back(conn[i][0]);
        }
        int c=0;
        for(int i=0; i<n; i++){
            if(!vis[i])
            {
                dfs(i,vis,adj);
                c++;
            }
        }
        return c-1;
    }
};