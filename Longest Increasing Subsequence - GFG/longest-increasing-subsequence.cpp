//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
    
    int solve(int a[],int n,int ind ,int prev,vector<vector<int>>& dp){
        if(ind==n) return 0;
        
        if(dp[ind][prev+1]!=-1) return dp[ind][prev+1];
        
        int len=solve(a,n,ind+1,prev,dp);
        if(prev==-1 || a[ind]>a[prev]){
            len= max(len, solve(a,n,ind+1,ind,dp)+1);
        }
        
        return dp[ind][prev+1]= len;
    }
    
    int longestSubsequence(int n, int a[])
    {
        
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
       return solve(a,n,0,-1,dp);
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}

// } Driver Code Ends