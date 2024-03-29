class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        
        vector<vector<int>> dp(n+2, vector<int>(2, 0));
        dp[n][0] = dp[n][1] = 0;
        
        for(int i=n-1; i>=0; i--)
        {
            for(int j=0; j<2; j++)
            {
                int profit=0;
                if(j==1)
                {
                    int buy = -prices[i] + dp[i+1][0];
                    int dontBuy = dp[i+1][1];
                    profit=max(buy, dontBuy);
                }
                else
                {
                    int sell = prices[i] + dp[i+1][1] - fee;
                    int dontSell = dp[i+1][0];   
                    profit=max(sell, dontSell);
                }

                dp[i][j] = profit;   
            }
        }
                                    
        return dp[0][1];
    }
};