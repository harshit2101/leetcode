class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int i = 0, N = nums.size(), odd = 0, ans = 0;
        int count = 0;
        for(int j = 0; j < N; j++) {
            if(nums[j] & 1) {
                odd++;
                count = 0;
            }
            
            while(odd == k) {
                odd -= nums[i++] & 1;
                ++count;
            }
            ans += count;
        }
        
        return ans;
    }
};