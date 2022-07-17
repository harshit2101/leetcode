class Solution {
public:
    
    bool detectCycle_util(vector<vector<int>>& adj, int cur,vector<int>& visited)
    {
        if(visited[cur]==1) return true;
        if(visited[cur]==2) return false;
        
        visited[cur]=1;
        for(auto it:adj[cur])
        {
            if(detectCycle_util(adj,it,visited)) return true;
        }
        visited[cur]=2;
        return false;
    }
    bool iscycle(vector<vector<int>>& adj,int numco)
    {
        vector<int> visited(numco,0);
        for(int i=0;i<numco;i++)
        {
            if(visited[i]!=1)
                if(detectCycle_util(adj,i,visited))
                    return true;
        }
        return false;
    }
    void toposort(int node,vector<vector<int>>&adj, stack<int>&s,  vector<int>&visited){
        visited[node]=1;
        for(auto it:adj[node]){
            if(visited[it]==0)
                toposort(it,adj,s,visited);
        }
        s.push(node);
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>ans;
        vector<vector<int>>adj(numCourses);
        for(int i=0;i<prerequisites.size();i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        vector<int>visited(numCourses,0);
        if(iscycle(adj,numCourses)) return {};
        visited.clear();
        stack<int>s;
        for(int i=0;i<numCourses;i++)
            if(visited[i]==0)
            toposort(i,adj,s,visited);
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        return ans;
    }
};