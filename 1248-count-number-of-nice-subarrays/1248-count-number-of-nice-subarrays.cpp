class Solution {
public:
    int atmost(vector<int>& nums, int k) {
        int n = nums.size();
         int cnt = 0;
         int i=0,j=0;
         int ans = 0;
         while(j<n){
             if(nums[j]&1)
                   cnt++;
             if(cnt>k){
                 while(i<=j && cnt>k){
                     if(nums[i]&1)
                          cnt--;
                     i++;
                 }
             }
             ans+=(j-i+1);
             j++;
         }
         return ans;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atmost(nums,k) - atmost(nums,k-1);
    }
};