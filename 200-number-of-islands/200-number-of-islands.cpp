class Solution {
public:
    
    
    void solve(vector<vector<char>>& grid,int i,int j,int row,int col){
        if(i<0 || j<0 || i>=row || j>=col || grid[i][j]!='1'){
            return;
        }
        
        grid[i][j]='2';
        
        solve(grid,i+1,j,row,col);
        solve(grid,i,j+1,row,col);
        solve(grid,i-1,j,row,col);
        solve(grid,i,j-1,row,col);
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        
        if(row==0) return 0;
        int count=0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]=='1'){
                    solve(grid,i,j,row,col);
                    count++;
                }
            }
        }
        return count;
    }
};