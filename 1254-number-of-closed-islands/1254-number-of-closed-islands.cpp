class Solution {
public:
    
    int dx[4]={1,-1,0,0}, dy[4]={0,0,1,-1};
    void dfs(int i, int j,int n,int m, vector<vector<int>>& grid){
        grid[i][j]=1;
        
        for(int k=0;k<4;k++){
            int x=i+dx[k];
            int y=j+dy[k];
            
            if(x>=0 && x<n && y>=0 && y<m && grid[x][y]==0){
                dfs(x,y,n,m,grid);
            }
        }
    }
    
    
    int closedIsland(vector<vector<int>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i*j==0 || i==n-1 || j==m-1){
                    if(grid[i][j]==0){
                        dfs(i,j,n,m,grid);
                    }
                }
            }
        }
        
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    ans++;
                    dfs(i,j,n,m,grid);
                }
            }
        }
        
        return ans;
    }
};