class Solution {
public:
    
    #define INF 10000000;
    int dp[305][15];
    int solve(int index, int n, int d, vector<int>& jd){
        
        if(index==n && d==0) return 0;
        if(index==n || d==0 || n-index<d) return INF;
        if(dp[index][d]!=-1) return dp[index][d];
        
        int ans=INF;
        int maxi=-INF;
        
        for(int j=index;j<n;j++){
            maxi=max(maxi, jd[j]);
            ans=min(ans, maxi+solve(j+1,n,d-1,jd));
        }
        
        return dp[index][d]=ans;
    }
    
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        
        int n=jobDifficulty.size();
        
        if(n<d) return -1;
        
        memset(dp,-1,sizeof(dp));
        
        return solve(0,n,d,jobDifficulty);
    }
};
