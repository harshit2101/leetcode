class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp1(n+1,1),dp2(n+1,1);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[i]>nums[j] && 1+dp1[j]>dp1[i])
                {
                    dp1[i]=1+dp1[j];
                }
            }
        }
        
         for(int i=n-1;i>=0;i--)
        {
            for(int j=i+1;j<n;j++)
            {
                if(nums[i]>nums[j] && 1+dp2[j]>dp2[i])
                {
                    dp2[i]=1+dp2[j];
                }
            }
        }
        int temp=0;
        for(int i=0;i<n+1;i++)
        {
            if(dp1[i]>1&&dp2[i]>1)
                 temp=max(temp,dp1[i]+dp2[i]-1);
        }
        return n-temp;        
    }
};