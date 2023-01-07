//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
    long long int solve(int coins[],int n,int sum,vector<vector<long>>& dp){
        if(n==0){
            return (sum%coins[0]==0);
        }
        
        if(dp[n][sum]!=-1) return dp[n][sum];
        
        long long int take=0;
        long long int nottake= solve(coins, n-1,sum,dp);
        if(coins[n]<=sum) take=solve(coins,n,sum-coins[n],dp);
        
        
        return dp[n][sum] =take + nottake;
    }
  
    long long int count(int coins[], int N, int sum) {

        vector<vector<long>> dp(N, vector<long>(sum+1,0));
        // return solve(coins,N-1,sum,dp);
        
        
        for(int j=0;j<=sum;j++) dp[0][j]= j%coins[0]==0;
        
        for(int i=1;i<N;i++){
            for(int j=0;j<=sum;j++){
                long long int take=0;
                long long int nottake= dp[i-1][j];
                if(coins[i]<=j) take=dp[i][j-coins[i]];
                
                
                dp[i][j] =take + nottake;
            }
        }
        
        return dp[N-1][sum];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends