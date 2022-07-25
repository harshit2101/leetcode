class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        
        int n = nums.size();
        
        float total_sum = 0;
        for(auto& n: nums) total_sum+=n;
        
        
        float o_sum = (total_sum+target)/2;
        if(o_sum < 0) return 0;
        
        int i_sum = o_sum;
        float f_sum = i_sum;
        
        if(f_sum != o_sum) return 0;
        int sum = i_sum;
        
        int dp[n+1][sum+1];
        
        for(int i=0; i<=n; i++){
            for(int j=0; j<=sum; j++){
                if(i==0) dp[i][j] = (j==0);
                else if(nums[i-1] > j) dp[i][j] = dp[i-1][j];
                else dp[i][j] = dp[i-1][j] + dp[i-1][j-nums[i-1]];
            }
        }
        
        return dp[n][sum];
    }
};