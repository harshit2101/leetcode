class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        
        unordered_set<int> s;
        int l=0,curr_sum=0,max_sum=0;
        for(int num:nums){
            while(s.find(num)!=s.end()){
                curr_sum-=nums[l];
                s.erase(nums[l]);
                l++;
            }
            
            curr_sum+=num;
            s.insert(num);
            max_sum=max(max_sum,curr_sum);
        }
        return max_sum;
    }
};