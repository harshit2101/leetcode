class Solution {
public:
    
   bool canColor(vector<vector<int>>&graph, int src , vector<int>&color)
    {
        queue<int>q;
        color[src] = 1;
        q.push(src);
        while(!q.empty())
        {
            int front = q.front();
            q.pop();
            int parent_color = color[front];
            for(auto neigh : graph[front])
            {
                int cand = 1 - parent_color;
                if(color[neigh] == parent_color)
                    return false;
                if(color[neigh] == -1)
                {
                    color[neigh] = cand;
                    q.push(neigh);
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) 
    {
        int num_ver = graph.size();
        vector<int>color(num_ver, -1);
        
        for(int i = 0; i < num_ver; i++)
        {
            if(color[i] == -1)
            {
                if(canColor(graph, i, color) == false)
                    return false;
            }
        }
        return true;
    }
};