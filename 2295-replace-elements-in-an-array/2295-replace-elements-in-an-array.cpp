class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
        
        unordered_map<int,int> hm;    
        for(int i =0;i<nums.size();i++){
            
            hm[nums[i]] = i; 
        }
        
        for(int i =0;i<operations.size();i++){
            
            
            int a  = operations[i][0];
            int b = operations[i][1];
            
            nums[hm[a]] = b;
            
            hm[b] = hm[a];
            
            
        }
        return nums;
        
    }
};