class Solution {
public:
    int dir[5]= {0, 1, 0, -1, 0};
    bool valid(int x,int y,vector<vector<int>>& grid){
        int n = grid.size();
        int m = grid[0].size();
        if(x>=0 && y>=0 && x<n && y<m && grid[x][y]==1)return true;
        return false;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
       int n = grid.size();
       int m = grid[0].size();
        int maxm = INT_MIN;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                int c=0;
                if(grid[i][j]){
                    queue<pair<int,int>>q;
                    grid[i][j]=0;
                    q.push({i,j});
                    while(!q.empty()){
                        auto src = q.front();
                        
                        q.pop();
                        c++;
                        for(int i = 0;i<4;i++){
                        int dx = dir[i]+src.first;
                        int dy = dir[i+1]+src.second;
                            if(valid(dx,dy,grid)){
                                
                                q.push({dx,dy});
                                grid[dx][dy]=0;
                            }
                        }
                    }
                  
                }
                  maxm = max(maxm,c);
            }
        }
        return maxm;
    }
};