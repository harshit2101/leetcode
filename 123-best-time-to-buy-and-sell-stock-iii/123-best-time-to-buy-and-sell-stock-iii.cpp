class Solution {
public:
    
    int dp[100001][2][3];
        
//     int solve(int ind,int buy,int cap,vector<int> prices, int n){
        
//         if(cap==0 || ind==n) return 0;
        
//         if(dp[ind][buy][cap]!=-1) return dp[ind][buy][cap] ;
        
//         int profit=0;
        
//         if(buy==1){
//             profit= max(-prices[ind]+ solve(ind+1,0, cap,prices, n), solve(ind+1,1,cap, prices, n));
//         }
//         else{
//             profit= max(prices[ind]+ solve(ind+1,1, cap-1, prices, n), solve(ind+1,0, cap,prices, n));
//         }
        
//         return dp[ind][buy][cap] = profit;
//     }
    
    int maxProfit(vector<int>& prices) {
        
        int n=prices.size();
        memset(dp,0,sizeof(dp));
     
		// vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
		for(int i=n-1;i>=0;i--)
		{
			for(int buy=0;buy<=1;buy++)
			{
				for(int limit=1;limit<=2;limit++)
				{
					if(buy)
						dp[i][buy][limit] = max((-prices[i]+dp[i+1][0][limit]),dp[i+1][1][limit]);
					else
						dp[i][buy][limit] = max((prices[i]+dp[i+1][1][limit-1]),dp[i+1][0][limit]);  
				}
			}
		}
		return dp[0][1][2];
	}
};