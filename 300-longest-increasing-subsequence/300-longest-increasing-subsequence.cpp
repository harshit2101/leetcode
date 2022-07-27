class Solution {
public:
    int lengthOfLIS(vector<int>& arr1) {
        vector<int> temp = arr1;
        sort(temp.begin(), temp.end());
        
        vector<int> arr2;
        arr2.push_back(temp[0]);
        for(int i=1; i<temp.size(); i++){
            if(temp[i]!=temp[i-1]) arr2.push_back(temp[i]);
        }
        
        int a = arr1.size();
        int b = arr2.size();
        int dp[a+1][a+1];
        
        for(int i=0; i<=a; i++){
            for(int j=0; j<=b; j++){
                if(i==0 or j==0) dp[i][j] = 0;
                else if(arr1[i-1] == arr2[j-1]) dp[i][j] = 1+dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        
        return dp[a][b];
    }
};