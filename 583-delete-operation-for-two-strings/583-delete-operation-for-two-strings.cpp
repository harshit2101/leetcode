class Solution {
public:
    
    
    int lcs(string text1, string text2) {
        
        int m=text1.size();
        int n=text2.size();
        int dp[1001][1001];
        
        for(int i=0;i<m+1;i++){
            for(int j=0;j<n+1;j++){
                if(i==0 || j==0) dp[i][j]=0;
            }
        }
        
        
        for(int i=1;i<m+1;i++){
            for(int j=1;j<n+1;j++){
                if(text1[i-1]==text2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        
        return dp[m][n];
    }
    
    int minDistance(string word1, string word2) {
        
        int m=word1.size();
        int n=word2.size();
        
        return m+n - 2*(lcs(word1,word2));
        
    }
};