class Solution {
public:
    vector<pair<int,int>>dir={{1,0},{-1,0},{0,-1},{0,1}};
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int N=grid.size();
        int M=grid[0].size();
        int m_area=0;
        
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(grid[i][j]==0)continue;
                queue<pair<int,int>>q;
                q.push({i,j});
                int area=0;
                while(!q.empty()){
                    int n=q.size();
                    while(n--){
                        pair<int,int>p=q.front();
                        q.pop();
                        grid[p.first][p.second]=0;
                        for(auto k:dir){
                            int x=p.first+k.first;
                            int y=p.second+k.second;
                            
                            if(x>=0 and y>=0 and x<N and y<M and grid[x][y]==1){
                                grid[x][y]=0;
                                q.push({x,y});
                                area++;
                            }
                        }
                    }
                }
                m_area=max(area+1,m_area);
            }
        }
        return m_area;
    }
};