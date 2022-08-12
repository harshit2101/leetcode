class Solution {
public:
    
    int dp[302][302];
        
//     int solve(int i,int j,vector<int>& nums){
//         if(i>j) return 0;
//         if(dp[i][j]!=-1) return dp[i][j];
        
//         int maxi=INT_MIN;
        
//         for(int ind=i;ind<=j;ind++){
//             int cost=nums[i-1]*nums[ind]*nums[j+1]+ solve(i,ind-1,nums)+ solve(ind+1,j,nums);
//             maxi=max(maxi,cost);
//         }
        
//         return dp[i][j]= maxi;
//     }
    
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        memset(dp,0,sizeof(dp));
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        
        for(int i=n;i>=1;i--){
            for(int j=1;j<=n;j++){
                
                if(i>j) continue;
                
                int maxi=INT_MIN;
                for(int ind=i;ind<=j;ind++){
                    int cost=nums[i-1]*nums[ind]*nums[j+1]+ dp[i][ind-1]+ dp[ind+1][j];
                    maxi=max(maxi,cost);
                }

                dp[i][j]= maxi;
            }
        }
        
        
        return dp[1][n];
    }
};