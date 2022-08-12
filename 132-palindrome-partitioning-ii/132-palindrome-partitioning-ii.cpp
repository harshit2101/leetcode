class Solution {
public:
    int dp [2001];
private:
    bool ispalindrome(string &s,int i,int j){
       // if(i>=j){
       //      return true;
       //  }
        while(i<j){
            if(s[i]!=s[j]){
                return false;
            }
            else{
                i++;
                j--;
            }
        }
        return true;
    }
private:
    int solve(string &s,int i,int j){
        if(i==j){
            return 0;
        }
        
        // if(ispalindrome(s,i,j)){
        //     return dp[i][j] =0;
        // }
        
        if(dp[i]!=-1){
            return dp[i];
        }
        
        int mn = INT_MAX;
        for(int k =i;k<j;k++){
            if(ispalindrome(s,i,k)){
            int temp =solve(s,k+1,j)+1;
            mn = min(temp,mn);
            }
        }
        return dp[i]=mn;

    }
public:
    int minCut(string s) {
        memset(dp,-1,sizeof(dp));
        return solve(s,0,s.size())-1;

    }
};