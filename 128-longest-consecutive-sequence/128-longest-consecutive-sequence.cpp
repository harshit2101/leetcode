class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        unordered_set<int> s;
        for(auto x:nums){
            s.insert(x);
        }
        int count=0;
        for(int i=0;i<nums.size();i++){
            
            if(!s.count(nums[i]-1)){
                int curr_count=1;
                int curr_num=nums[i];
                
                while(s.count(curr_num+1)){
                    curr_count+=1;
                    curr_num+=1;
                }
            count=max(count,curr_count);  
            }
        }
        return count;
    }
};