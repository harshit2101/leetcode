class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        
        vector<int> ans;
        int sum=0;
        
        for(auto it:nums){
            if(it%2==0) sum+=it;
        }
        
        for(auto it:queries){
            int temp=nums[it[1]];
            
            if(temp%2==0) sum-=temp;
            
            nums[it[1]]+=it[0];
            
            if(nums[it[1]]%2==0) sum+=nums[it[1]];
            
            ans.push_back(sum);
            
        }
        
        return ans;
    }
};