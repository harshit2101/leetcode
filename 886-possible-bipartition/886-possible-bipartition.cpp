class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int> graph[n+1];
        
        for(auto &d : dislikes){
            graph[d[0]].push_back(d[1]);
            graph[d[1]].push_back(d[0]);
        }
        
        vector<int> color(n+1,-1);
        
        for(int i=1;i<=n;i++){
            if(color[i]==-1){
                
                color[i] = 1;
                queue<int> q;
                q.push(i);

                while(!q.empty()){
                    int node = q.front();
                    q.pop();
                    for(auto v : graph[node]){
                        if(color[v]==-1){
                            color[v] = 1-color[node];
                            q.push(v);
                        }
                        else if(color[v]==color[node])
                            return false;
                    }
                }
            }    
        }
        
        return true;
    }
};