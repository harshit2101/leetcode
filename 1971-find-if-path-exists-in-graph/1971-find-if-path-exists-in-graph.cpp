class Solution {
public:
    void dfs(int source, vector<bool>&visited, vector<int> graph[])
    {
        visited[source] = 1;
        for(auto g:graph[source])
            if(!visited[g])
                dfs(g,visited,graph);
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int> graph[n];
        vector<bool>visited(n,0);
        int m=edges.size();
        for(int i=0;i<m;i++)
        {
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        dfs(source,visited,graph);
        return visited[destination];
    }
};