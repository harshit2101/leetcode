class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        
        int prefsum=0;
        unordered_map<int,int> m={{0,-1}};
        
        for(int  i=0;i<nums.size();i++){
            prefsum+=nums[i];
            // prefsum%=k;
            
            // if(prefsum==0 && i) return true;
            
            if(m.find(prefsum%k)!=m.end()){
                if(i-m[prefsum%k]>1) return true;
            }
            else m[prefsum%k]=i;
        }
        
        return false;
    }
};
