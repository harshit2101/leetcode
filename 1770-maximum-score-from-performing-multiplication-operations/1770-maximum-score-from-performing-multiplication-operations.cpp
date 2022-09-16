class Solution {
public:
    
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int n = nums.size();
        int m = multipliers.size();
        int dp[1005];

        for (int i = 1; i <= m; i++) dp[i] = INT_MIN;
        dp[0] = 0;
        
        for (int i = 1; i <= m; i++) {
            // dp[k] -> k rear elements has been used
            int mult = multipliers[i - 1];
            for (int k = i; k >= 0; k--) {
                int nv = INT_MIN;
                if (dp[k] > INT_MIN) {
                    nv = max(nv, dp[k] + nums[i - k - 1] * mult);                                   }
                if (k > 0) {
                    nv = max(nv, dp[k - 1] + nums[n - k] * mult);
                }
                dp[k] = nv;
            }
        }
        
        int ans = dp[0];
        for (int i = 1; i <= m; i++) {
            ans = max(ans, dp[i]);
        }

        return ans;
    }
};