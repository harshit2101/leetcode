class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int median=nums[n/2];
        int count=0;
        for(int i=0;i<nums.size();i++){
            count+=abs(median-nums[i]);
        }
        return count;
    }
};