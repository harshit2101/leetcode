class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        if(k==1) return 0;
        int n=nums.size();
        int res=INT_MAX;
        sort(nums.begin(),nums.end());
        for(int i=k-1;i<n;i++){
            res=min(res,nums[i]-nums[i-k+1]);
        }
        
        return res;
    }
};