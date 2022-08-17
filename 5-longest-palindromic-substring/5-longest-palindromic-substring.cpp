class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
		
       
        string t = s;
        reverse(t.begin(), t.end());
        
		
        int dp[n+1][n+1];
        int mx = INT_MIN;
        string ans = "";
        
        for(int i=0 ;i<n+1; ++i)
            for(int j=0; j<n+1; ++j)
                if(i==0 || j==0)
                    dp[i][j] = 0;
        
        for(int i=1 ;i<n+1; ++i){
            for(int j=1; j<n+1; ++j){
                if(s[i-1] == t[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                    
                    
                    if(dp[i][j] > mx){
                        string temp=s.substr(i-dp[i][j],dp[i][j]);
                        string revtemp=temp;
                        reverse(revtemp.begin(),revtemp.end());
                        if(revtemp==temp){
                            mx=dp[i][j];
                            ans=temp;
                        }
                    }
                    
                }
                else{
                    dp[i][j] = 0; 
                }
            }
        }
        return ans;
    }
};
