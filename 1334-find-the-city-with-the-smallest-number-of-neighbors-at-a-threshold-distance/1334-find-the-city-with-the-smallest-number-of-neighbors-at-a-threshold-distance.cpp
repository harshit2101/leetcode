class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        
        vector<vector<int>> matrix(n, vector<int>(n,INT_MAX/2));
        
        for(auto it:edges){
            matrix[it[0]][it[1]]=it[2];
            matrix[it[1]][it[0]]=it[2];
        }
        
        // for(int i=0;i<n;i++) matrix[i][i]=0;
        
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    matrix[i][j]=min(matrix[i][j], matrix[i][k]+matrix[k][j]);
                }
            }
        }
        
        int mincount=INT_MAX, ans=-1;
        
        for(int i=0;i<n;i++){
            int count=0;
            for(int j=0;j<n;j++){
                if(i!=j && matrix[i][j]<=distanceThreshold) count++;
            }
            if(count<=mincount){
                mincount=count;
                // ans=max(ans,i);
                ans=i;
            }
        }
        
        return ans;
    }
};

