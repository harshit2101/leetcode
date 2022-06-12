class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        
        int n=nums.size();
        vector<int> p(n+1,0);
        for(int i=0;i<n;i++){
            p[i+1]=p[i]+nums[i];
        }
        int s=0;
        int ans=0;
        vector<int> m(10001,-1);
        for(int i=0;i<n;i++){
            s=max(s,m[nums[i]]+1);
            ans=max(ans,p[i+1]-p[s]);
            m[nums[i]]=i;
        }
        return ans;
    }
};