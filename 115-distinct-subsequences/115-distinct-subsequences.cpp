class Solution {
public:
    
//     int solve(int i,int j, string s, string t,vector<vector<int>> dp){
//         if(j==0) return 1; //matched
//         if(i==0) return 0; //unmatched
//         if(dp[i][j]!=-1) return dp[i][j];
        
//         if(s[i-1]==t[j-1]){
//             return dp[i][j] =(solve(i-1,j-1,s,t,dp)+solve(i-1,j,s,t,dp));
//         }
//         else{
//             return dp[i][j]= solve(i-1,j,s,t,dp);
//         }
//     }
    
    int numDistinct(string s, string t) {
        int n=s.size();
        int m=t.size();
        vector<double> prev(m+1,0), cur(m+1,0);
        
        
       
        int i,j;

        prev[0]=cur[0]=1;
            
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            {
                if(s[i-1]==t[j-1])
                {
                    cur[j]=prev[j-1]+prev[j];
                    
                }
                else
                    cur[j]=prev[j];
            }
            prev=cur;
        }

        return prev[m];
    }
};