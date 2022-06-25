class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        int l=0,r=0,sum=0;
        int ans=INT_MAX;
        
        while(r<n){
            sum+=nums[r];
            
            if(sum>=target){
                while(sum>=target){
                    sum-=nums[l];
                    l++;
                }             
                ans=min(ans,r-l+2);
            }
            r++;
        }
        return ans==INT_MAX?0:ans;
    }
};