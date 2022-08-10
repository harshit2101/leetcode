class Solution {
public:
    
    int dp[2500][2501];
    
    int solve(int ind,int prev, vector<int>& nums, int n){
        if(ind==n) return 0;
        if(dp[ind][prev+1]!=-1) return dp[ind][prev+1];
        
        int len=0;
        
        len=solve(ind+1,prev,nums,n);
        if(prev==-1 || nums[ind]>nums[prev]){
            len=max(len,1 + solve(ind+1,ind,nums,n));
        }
        
        return dp[ind][prev+1]= len;
    }
    
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        memset(dp,-1,sizeof(dp));
        
        return solve(0,-1,nums,n);
    }
};