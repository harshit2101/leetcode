class Solution {
public:
    
     int maxProfit(int k, vector<int>& prices) {
        int n = prices.size(), m = 2*k+1;
        vector<int> dp(m, 0);
        
        for(int idx = n-1; idx >= 0; idx--) {
            for(int jdx = m-1; jdx > 0; jdx--) {
                if(jdx % 2 == 0)
                    dp[jdx] = max(dp[jdx],-prices[idx] + dp[jdx-1]);
                else 
                    dp[jdx] = max(dp[jdx], prices[idx] + dp[jdx-1]);
            }
        }
        
        return dp[m-1];
    }
};