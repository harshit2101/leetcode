//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    
    void bfs(vector<vector<char>>& grid, int m,int n, vector<vector<int>>& vis,int row,int col){
        vis[row][col]=1;
        queue<pair<int,int>>q;
        q.push({row,col});
        
        while(!q.empty()){
            int nrow=q.front().first;        
            int ncol=q.front().second;
            q.pop();
            
            for(int i=-1;i<=1;i++){
                for(int j=-1;j<=1;j++){
                    int nr=nrow+i;
                    int nc=ncol+j;
                    
                    if(nr>=0 && nr<m && nc>=0 && nc<n && grid[nr][nc]=='1' && !vis[nr][nc]){
                        vis[nr][nc]=1;
                        q.push({nr,nc});
                    }
                }
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        int count=0;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    count++;
                    bfs(grid,m,n,vis,i,j);
                }
            }
        }
        
        return count;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends