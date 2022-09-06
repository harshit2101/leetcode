class Solution {
public:
    bool dfs(int i, vector<vector<int>> &graph, vector<bool> &visited, vector<bool> &mark, vector<bool> &cycle){
         mark[i] = true;
         if(!visited[i]){
             visited[i] = true;
             for(auto it : graph[i]){
                 if(!visited[it] && dfs(it, graph, visited, mark, cycle)){
                     return cycle[i] = true;
                 }
                 if(mark[it]) return cycle[i] = true;
             }
         }
         mark[i] = false;
         return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<bool> visited(n, 0), mark(n, 0), cycle(n, 0);
        for(int i = 0; i<n; i++){
            if(!visited[i]){
                dfs(i, graph, visited, mark, cycle);
            }
        }
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            if (!cycle[i])
                ans.push_back(i);
        }
        return ans;
    }
};