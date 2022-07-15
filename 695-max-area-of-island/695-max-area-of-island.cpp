class Solution {
public:
    
    int solve(vector<vector<int>>& grid,int r,int c){
        if(r>=0 && r<grid.size() && c>=0 && c<grid[0].size() && grid[r][c]==1){
            grid[r][c]=0;
            return (1+ solve(grid,r+1,c) + solve(grid,r-1,c) + solve(grid,r,c+1) + solve(grid,r,c-1));
        }
        return 0;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans=max(ans,solve(grid,i,j));
            }
        }
        return ans;
    }
};