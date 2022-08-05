class Solution {
public:
    int rob(vector<int>& nums, int start, int len) {
        int prevPrev = 0;       // max sum for 2 houses previous
        int prev = nums[start]; // max sum for previous house
        int curr;
        for (int i = 2; i < len + 1; i++) {
            curr = max(prevPrev + nums[start+i-1], prev);
            prevPrev = prev;
            prev = curr;
        }
        return curr;
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        
        return max(rob(nums, 0, n-1), rob(nums, 1, n-1));
    }
};