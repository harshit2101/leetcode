class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        
        int n=nums.size();
        unordered_map<int, int> m;
        int sum=0;
        int count=0;
        
        for(int i=0;i<n;i++){
            sum+=nums[i];
            
            if(sum%k==0) count++;
            
            int remainder=sum%k;
            
            if(remainder<0) remainder+=k;
            
            if(m.find(remainder)!=m.end()){
                count+=m[remainder];
            }
            
            m[remainder]++;
        }
        
        return count;
    }
};