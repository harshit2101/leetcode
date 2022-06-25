class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int i=0,j=0;
        int sum=0,maxi=INT_MIN;
        while(j<nums.size()){
            sum+=nums[j];
            if(j-i+1<k){
                j++;
            }
            else if(j-i+1==k){
                maxi=max(sum,maxi);
                sum=sum-nums[i];
                i++,j++;
            }
        }
        
        return (double)maxi/k;
    }
};