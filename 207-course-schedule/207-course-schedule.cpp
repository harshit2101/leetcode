class Solution {
public:
    
    
    bool solve(vector<int> adj[],vector<int>& dfsvis,vector<int>& vis, int node){
        
        vis[node]=1,dfsvis[node]=1;
        
        for(auto it: adj[node]){
            if(!vis[it]){
                if(solve(adj,dfsvis,vis,it)) return true;
            }
            if(dfsvis[it]) return true;
        }
        
        dfsvis[node]=0;
        return false;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<int> adj[numCourses];
        
        for(int i=0;i<prerequisites.size();i++){
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        
        vector<int> vis(numCourses,0);
        vector<int> dfsvis(numCourses,0);
        
        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
                if(solve(adj,dfsvis,vis,i)) return false;
            }
        }
        return true;
    }
};