class Solution {
public:
    
   int dp[50000];
    
    bool f(int i, int sum, vector<int>& nums, int n)
    {
        if(sum == 0)
            return true;
    
        if(i == n or sum < 0)
            return false;
        
        if(dp[sum] != -1)
            return dp[sum];
        
        return dp[sum] = f(i + 1, sum - nums[i], nums, n) || f(i + 1, sum, nums, n);
    }
    
    bool canPartition(vector<int>& nums) 
    {
        int n = (int)nums.size();
        int sum = 0;
        for(int i = 0; i < n; i++)
        {
            sum += nums[i];
        }
        if(sum & 1)
        {
            return false;
        }
        memset(dp, -1, sizeof(dp));
        return f(0, sum / 2, nums, n);
    }
};