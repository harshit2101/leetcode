class Solution {
public:
    
//     int dp[2500][2501];
    
//     int solve(int ind,int prev, vector<int>& nums, int n){
//         if(ind==n) return 0;
//         if(dp[ind][prev+1]!=-1) return dp[ind][prev+1];
        
//         int len=0;
        
//         len=solve(ind+1,prev,nums,n);
//         if(prev==-1 || nums[ind]>nums[prev]){
//             len=max(len,1 + solve(ind+1,ind,nums,n));
//         }
        
//         return dp[ind][prev+1]= len;
//     }
    
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
     
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        
        for(int ind = n-1;ind>=0;ind--){
            for(int prev = ind-1;prev>=-1;prev--){
                
        int nottake = dp[ind+1][prev+1];
        int take =0;
        if(prev==-1 || nums[ind]>nums[prev]){
            take = 1+dp[ind+1][ind+1];
        }
        dp[ind][prev+1]=max(nottake,take);
            }
        }
        return dp[0][0];
		}
};