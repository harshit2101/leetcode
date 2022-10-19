class Solution {
public:
    
    int dp[46];
    
    int solve(int n){
        
        if(n==0) return 1;
        if(n==1) return 1;
        if(dp[n]!=-1) return dp[n];
        
        int left=solve(n-1);
        int right=solve(n-2);
        
        return dp[n]= left+right;
    }
    
    int climbStairs(int n) {
        
        memset(dp,-1,sizeof(dp));
        return solve(n);
    }
};