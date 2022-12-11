//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
	
	void  topo(vector<int> adj[], vector<int>& vis, stack<int>& st, int node){
	    vis[node]=1;
	    
	    for(auto it:adj[node]){
	        if(!vis[it]){
	            topo(adj,vis,st,it);
	        }
	    }
	    st.push(node);
	}
	
	void  dfs(vector<int> adj[], vector<int>& vis, int node){
	    vis[node]=1;
	    
	    for(auto it:adj[node]){
	        if(!vis[it]){
	            dfs(adj,vis,it);
	        }
	    }
	}
	
    int kosaraju(int V, vector<int> adj[])
    {
        vector<int> vis(V,0);
        stack<int> st;
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                topo(adj,vis,st,i);
            }
        }
        
        vector<int> adjT[V];
        for(int i=0;i<V;i++){
            vis[i]=0;
            for(auto it:adj[i]){
                adjT[it].push_back(i);
            }
        }
        
        int scc=0;
        
        while(!st.empty()){
            int node=st.top();
            st.pop();
            
            if(!vis[node]){
                scc++;
                dfs(adjT,vis,node);
            }
        }
        
        return scc;
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends