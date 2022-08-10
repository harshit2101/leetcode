class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        
        int n=nums.size();
        vector<int> dp(n,1);
        vector<int> hash(n,0);
        vector<int> res;
        
        sort(nums.begin(), nums.end());
        
        int mx=1;
        int mx_idx=0;
        
        for(int i=1;i<n;i++){
            hash[i]=i;
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0 && dp[i]<dp[j]+1){
                    dp[i]=dp[j]+1;
                    hash[i]=j;
                }
            }
            
            if(mx<dp[i]){
                mx=dp[i];
                mx_idx=i;
            }
        }

        while(hash[mx_idx]!=mx_idx){
            res.push_back(nums[mx_idx]);
            mx_idx=hash[mx_idx];
        }
        
        res.push_back(nums[mx_idx]);
    
        return res;
    }
};