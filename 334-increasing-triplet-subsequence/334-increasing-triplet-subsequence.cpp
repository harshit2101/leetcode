class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        
        int ind1=INT_MAX, ind2=INT_MAX;
        
        for(int i=0;i<nums.size();i++){
            if(nums[i]<=ind1) ind1=nums[i];
            else if(nums[i]<=ind2) ind2=nums[i];
            else return true;
        }
        
        return false;
    }
};