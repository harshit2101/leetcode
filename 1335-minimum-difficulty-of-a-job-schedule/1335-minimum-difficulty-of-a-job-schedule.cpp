// class Solution {
// public:
    
//     int dp[305][15];
//     int solve(int index, int n, int d, vector<int>& jd){
        
//         if(index==n && d==0) return 0;
//         if(index==n || d==0 || n-index<d) return 1e8;
//         if(dp[index][d]!=-1) return dp[index][d];
        
//         int ans=1e8, maxi=-1e8;
        
//         for(int j=index;j<n;j++){
//             maxi=max(maxi, jd[j]);
//             ans=min(ans, maxi+solve(index+1,n,d-1,jd));
//         }
        
//         return dp[index][d]=ans;
//     }
    
//     int minDifficulty(vector<int>& jobDifficulty, int d) {
        
//         int n=jobDifficulty.size();
        
//         if(n<d) return -1;
        
//         memset(dp,-1,sizeof(dp));
        
//         return solve(0,n,d,jobDifficulty);
//     }
// };


#define INF 10000000
class Solution {
public:
    int n;
    int dp[305][15];
    int dfs(int i,int d,vector <int> &jd)
    {
        if(i==n && d==0) return 0;
        if(i==n || d==0 || n-i<d) return INF;
        if(dp[i][d]!=-1) return dp[i][d];
        
        int ans=INF;
        int maxele=-INF;
        
        for(int j=i;j<n;j++)
        {   
            maxele=max(maxele,jd[j]); 
            ans=min(ans,maxele+dfs(j+1,d-1,jd)); 
        }
        
        dp[i][d]=ans;
        return ans;
    }
    
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        n=jobDifficulty.size();
        
        if(n<d)  return -1;
        memset(dp,-1,sizeof(dp));
        int ans= dfs(0,d,jobDifficulty);
        return ans;
    }
};