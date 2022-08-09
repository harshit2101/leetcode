class Solution {
public:
    
    
//     int solve(int ind,int buy,vector<int> prices, int n, vector<vector<int>>& dp){
//         if(ind==n) return 0;
//         if(dp[ind][buy]!=-1) return dp[ind][buy];
        
//         int profit=0;
        
//         if(buy){
//             profit= max(-prices[ind]+ solve(ind+1,0, prices, n,dp), solve(ind+1,1, prices, n,dp));
//         }
//         else{
//             profit= max(prices[ind]+ solve(ind+1,1, prices, n,dp), solve(ind+1,0, prices, n,dp));
//         }
        
//         return dp[ind][buy]= profit;
//     }
    
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        
        //Shifting the index to handle base case easily
        vector<vector<int>> dp(n+1, vector<int>(2, 0));
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
                    int sell = prices[i] + dp[i+1][1];
                    int dontSell = dp[i+1][0];   
                    profit=max(sell, dontSell);
                }

                dp[i][j] = profit;   
            }
        }
                                    
        return dp[0][1];
    }
};