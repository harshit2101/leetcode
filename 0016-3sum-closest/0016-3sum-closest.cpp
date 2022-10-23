class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        sort(nums.begin(),nums.end());
        int ans=INT_MAX, res=INT_MAX;
        for(int i=0;i<nums.size()-2;i++){
            
            int lo=i+1, hi=nums.size()-1;
            int sum=0;
            while(lo<hi){
                sum=nums[i]+nums[lo]+nums[hi];
                
                if(sum==target) return sum;
                else if(sum<target) lo++;
                else hi--;
                
                if(abs(sum-target)<ans){
                    ans=abs(sum-target);
                    res=sum;
                }
                
            }
        }
        
        return res;
    }
};