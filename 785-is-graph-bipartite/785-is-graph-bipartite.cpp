class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> color(n,0);    
        for(int i=0;i<n;i++)                 
        {
            if(!color[i]){
                
                queue<int> q;
                q.push(i);
                color[i]=1;
                while(!q.empty())
                {
                    int parent=q.front();
                    q.pop();
                    for(auto it:graph[parent])
                    {
                        if(color[it]==0)
                        {
                            color[it]=-color[parent];
                            q.push(it);
                        }
                        else
                        {
                            if(color[parent]==color[it]) return false;    
                        }
                    }
                }
            
            }     

        }
        return true;
    }
};