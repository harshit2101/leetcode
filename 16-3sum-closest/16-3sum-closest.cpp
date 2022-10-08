class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        int n=nums.size();
        int ans=0, min_diff=INT_MAX;
        
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<n-2;i++){
            
            int left=i+1;
            int right=n-1;
            
            while(left<right){
                
                int sum=nums[i]+nums[left]+nums[right];
                if(abs(target-sum)<min_diff){
                    min_diff=abs(target-sum);
                    ans=sum;
                }
                
                if(sum<target) left++;
                else right--;
            }
        }
        
        return ans;
    }
};