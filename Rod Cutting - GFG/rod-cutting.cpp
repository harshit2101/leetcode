//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
  
    int solve(int price[],int n, int ind,vector<vector<int>>& dp){
        if(ind==0){
            return n*price[0];   //because last 
        }
        
        if(dp[ind][n]!=-1) return dp[ind][n];
        
        
        // int take=INT_MIN;
        int rodL=ind+1;
        if(rodL<=n) return dp[ind][n]=price[ind]+solve(price,n-rodL,ind,dp);
        return dp[ind][n]=solve(price,n,ind-1,dp);
        // return dp[ind][n]= max(nottake,take);
    }
  
    int cutRod(int price[], int n) {
        
        vector<vector<int>> dp(n,vector<int>(n+1,0));
        // return solve(price,n,n-1,dp);
        
        for(int j=0;j<=n;j++){
            dp[0][j]=j*price[0];
        }
        
        
        for(int i=1;i<n;i++){
            for(int j=0;j<=n;j++){
                int nottake=dp[i-1][j];
                int take=INT_MIN;
                int rodL=i+1;
                if(rodL<=j) take=price[i]+dp[i][j-rodL];
                
                dp[i][j]= max(nottake,take);
            }
        }
        
        return dp[n-1][n];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends