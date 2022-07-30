class Solution {
public:
    int dp[101][10002];
    
    int solve(int k,int n){
        if(n==0 || n==1) return n;
        if(k==1) return n;
        if(dp[k][n]!=-1) return dp[k][n];
        
        int mn = INT_MAX;
        int left = 1, right = n;
        while(left<=right){
            int i = left + (right-left)/2;
            int left_result = solve(k-1,i-1);
            int right_result = solve(k,n-i);
            mn = min(mn, 1+max(left_result,right_result));
            if(left_result < right_result){
                left = i+1;
            }
            else
                right = i-1;
        }
        
        return dp[k][n]=mn;
    }
    
    
    int superEggDrop(int k, int n) {
        memset(dp,-1,sizeof(dp));
        return solve(k,n);
    }
};