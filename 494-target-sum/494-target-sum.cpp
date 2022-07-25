class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        
        int n = nums.size();
        int sum = 0;
        
        for(int i=0;i<n;i++) sum+=nums[i];
        int m = sum + target;
        
        if(m%2!=0 || m<0) return 0;
        
        
        m = m/2;
        int dp[21][2001];
        memset(dp, 0, sizeof(dp));
        
        for(int i=0;i<=n;i++) dp[i][0] = 1;
        for(int j=1;j<=m;j++) dp[0][j] = 0;
        
        
        for(int i=1;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(nums[i-1]<=j) dp[i][j] = dp[i-1][j-nums[i-1]] + dp[i-1][j];
                else dp[i][j] = dp[i-1][j];
            }
        }
        return dp[n][m];
    }
};