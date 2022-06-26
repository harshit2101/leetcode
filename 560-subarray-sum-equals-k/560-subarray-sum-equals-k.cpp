class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        int n=nums.size();
        if(n==0) return 0;
        
        int i=0,sum=0,c=0;
        unordered_map<int,int> m;
        while(i<n){
            sum+=nums[i];
            
            if(sum==k) c++;
            
            if(m.find(sum-k)!=m.end()){
                c+=m[sum-k];
            }
            m[sum]++;
            i++;
        }
        return c;
    }
};