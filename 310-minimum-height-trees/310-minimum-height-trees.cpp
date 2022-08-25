class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
       vector<int> indegree(n, 0);
        vector<bool> visited(n, false);
        unordered_map<int, vector<int>> graph;
        
        for(auto i: edges){
            graph[i[0]].push_back(i[1]);
            graph[i[1]].push_back(i[0]);
            indegree[i[0]]++;
            indegree[i[1]]++;
        }

        queue<int> q;
        for(int i=0; i<n; i++) 
            if(indegree[i] == 1 || indegree[i] == 0) q.push(i);
        
        int count = 0;
        while(!q.empty()){
            if(count == n-1 || count == n-2) break;
            int N = q.size();
            for(int i=0; i<N; i++){
                count++;
                int node = q.front();
                q.pop();
                visited[node] = true;
                for(auto child: graph[node]){
                    if(visited[child]) continue;
                    indegree[child]--;
                    if(indegree[child] == 1) q.push(child);
                }
            }
        }

        vector<int> ans;
        while(!q.empty())
            ans.push_back(q.front()), q.pop();
        return ans;
    }
};