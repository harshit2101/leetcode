class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
		vector<int> adj[n + 1];
		
        
		for (auto i : dislikes)
		{
			adj[i[0]].push_back(i[1]);
			adj[i[1]].push_back(i[0]);
		}
		
        
		vector<int>color(n + 1, -1);
		for (int i = 0; i < n; i++)
		{
			if (color[i] == -1)
			{
				if (!possibleToColor(i, adj, color))
				{
					return false;
				}
			}
		}
		return true;
	}

	bool possibleToColor(int node, vector<int> adj[], vector<int>&color)
	{
		if(color[node]==-1) color[node]=1;
        
		for (auto i : adj[node])
		{
			if (color[i] == -1)
			{
				color[i]=1-color[node];
                possibleToColor(i, adj, color);
			}
			else if (color[i] == color[node])
			{
				return false;
			}
		}
		return true;
	}
};