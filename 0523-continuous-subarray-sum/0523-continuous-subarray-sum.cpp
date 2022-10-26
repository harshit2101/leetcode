class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        
        int prefsum=0;
        unordered_map<int,int> m;
        
        for(int  i=0;i<nums.size();i++){
            prefsum+=nums[i];
            prefsum%=k;
            
            if(prefsum==0 && i) return true;
            
            if(m.find(prefsum)!=m.end()){
                if(i-m[prefsum]>1) return true;
            }
            else m[prefsum]=i;
        }
        
        return false;
    }
};
