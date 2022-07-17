class Solution {
public:
    
    void dfs(int node,vector<int>adj[],stack<int>&st,vector<int>&vis,vector<int>&cycle,bool &ispos){
        vis[node]=1;
        cycle[node]=1;
        for(auto i:adj[node]){
            if(!vis[i]){
                dfs(i,adj,st,vis,cycle,ispos);
            }else if(vis[i] && cycle[i]){
                ispos=false;
            }
        }
        cycle[node]=0;
        st.push(node);
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>adj[numCourses];
        for(auto i:prerequisites){
            int a=i[0];
            int b=i[1];
            adj[b].push_back(a);
        }
        stack<int>st;
        vector<int>vis(numCourses,0);
        vector<int>cycle(numCourses,0);
        bool ispos=true;
        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
                dfs(i,adj,st,vis,cycle,ispos);
            }
        }
        vector<int>ans;
        if(ispos){
            while(!st.empty()){
                ans.push_back(st.top());
                st.pop();
            }
        }
        return ans;
    }
};