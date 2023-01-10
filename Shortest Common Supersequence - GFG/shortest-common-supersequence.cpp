//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++


class Solution
{
    public:
    //Function to find length of shortest common supersequence of two strings.
    
    int solve(string x,string y, int m, int n,vector<vector<int>>& dp){
        
        if(m==0 || n==0) return 0;
        if(dp[m][n]!=-1) return dp[m][n];
        
        if(x[m-1]==y[n-1]){
            return dp[m][n]= solve(x,y,m-1,n-1,dp)+1;
        }
        
        return dp[m][n]= max(solve(x,y,m-1,n,dp), solve(x,y,m,n-1,dp));
    }
    
    int shortestCommonSupersequence(string X, string Y, int m, int n)
    {
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        int ans=solve(X,Y,m,n,dp);
        
        return m+n-ans;
    }
};

//{ Driver Code Starts.

int main()
{   
    
    int t;
    
    //taking total testcases
    cin >> t;
    while(t--){
    string X, Y;
    //taking String X and Y
	cin >> X >> Y;
	
	//calling function shortestCommonSupersequence()
	Solution obj;
	cout << obj.shortestCommonSupersequence(X, Y, X.size(), Y.size())<< endl;
    }
	return 0;
}


// } Driver Code Ends