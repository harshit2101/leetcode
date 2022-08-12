class Solution {
public:
    
    int dp[501];
    int solve(int ind,int n,int k, vector<int>& arr){
        if(ind==n) return 0;
        if(dp[ind]!=-1) return dp[ind];
        
        int ans=INT_MIN, len=0, maxi=INT_MIN;
        
        for(int i=ind;i<min(n,ind+k);i++){
            len++;
            maxi=max(maxi,arr[i]);
            
            int sum= (len*maxi)+ solve(i+1,n,k,arr);
            
            ans=max(ans,sum);
        }
        
        return dp[ind]= ans;
    }
    
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        memset(dp,-1,sizeof(dp));
        return solve(0,n,k,arr);
    }
};