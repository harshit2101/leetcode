//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
	
	
	int solve(int x, int y, string& s1, string& s2,vector<vector<int>>& dp){
        if(x<0 || y<0) return 0;
        
        if(dp[x][y]!=-1) return dp[x][y];
        
        if(s1[x]==s2[y]){
            return dp[x][y]= 1+ solve(x-1,y-1,s1,s2,dp);
        }
        
        return dp[x][y]= max(solve(x-1,y,s1,s2,dp),solve(x,y-1,s1,s2,dp));
    }
	
	int minOperations(string str1, string str2) 
	{ 
	    int n=str1.size();
	    int m=str2.size();
	    vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
	    int ans= solve(n-1,m-1,str1,str2,dp);
	   
	    return n+m-2*(ans);
	} 
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

	    Solution ob;
	    cout << ob.minOperations(s1, s2) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends