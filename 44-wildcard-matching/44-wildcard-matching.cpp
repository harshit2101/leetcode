class Solution {
public:
    
    
//     bool helper(int i,int j,string &p,string &s,vector<vector<int>> &dp)
//     {
//         if(i<0 && j<0) return true;
        
//         if(i<0 && j>=0) return false;
        
//         if(j<0 && i>=0)
//         {
//             for(int k=0;k<=i;++k)
//             {
//                 if(p[k]!='*')
//                     return false;
//             }
//             return true;
//         }
        
//         if(dp[i][j]!=-1) return dp[i][j];
        
//         if(p[i]==s[j] || p[i]=='?') return dp[i][j]=helper(i-1,j-1,p,s,dp);
        
//         if(p[i]=='*') return dp[i][j]=helper(i-1,j,p,s,dp) || helper(i,j-1,p,s,dp);
        
//         return dp[i][j]=false;
//     }
    bool isMatch(string s, string p) {
        int m=s.size(),n=p.size();
        vector<int> prev(m+1),curr(m+1);
        prev[0]=true;
        for(int i=1;i<=n;++i)
        {
            bool flag=true;
            for(int k=1;k<=i;++k)
            {
                if(p[k-1]!='*')
                {
                    flag=false;
                    break;
                }
            }
            curr[0]=flag;
            for(int j=1;j<=m;++j)
            {
                if(p[i-1]==s[j-1] || p[i-1]=='?')
                    curr[j]=prev[j-1];
                else if(p[i-1]=='*')
                    curr[j]=prev[j] || curr[j-1];
                else
                    curr[j]=false;
            }
            prev=curr;
        }
        return prev[m];
    }
};