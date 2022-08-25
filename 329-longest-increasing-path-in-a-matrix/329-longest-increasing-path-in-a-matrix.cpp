class Solution {
public:
    
    int dp[201][201];
    int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
    int dfs(vector<vector<int>>& matrix,int m,int n,int i, int j){
        
        if(dp[i][j]) return dp[i][j];
        int maxi=0;
        for(auto d:dir){
            int x=i+d[0], y=j+d[1];
            if(x>=0 && y>=0 && x<m && y<n && matrix[x][y]>matrix[i][j]){
                maxi=max(maxi,dfs(matrix,m,n,x,y));
            }
        }
        return dp[i][j]= maxi+1;
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if(matrix.size()==0) return 0;
        
        int m=matrix.size(), n=matrix[0].size();
        int longestPath=0;
        
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int path=dfs(matrix,m,n,i,j);
                longestPath=max(longestPath,path);
            }
        }
        
        return longestPath;
        
    }
};