class Solution {
    
public: 
    int solve(vector<int>&nums,int i, int j){
        if(i>j){
            return 0;
        }
        
        int choice1=nums[i]+min(solve(nums,i+2,j),solve(nums,i+1,j-1));
        int choice2=nums[j]+min(solve(nums,i,j-2),solve(nums,i+1,j-1));
        
        return max(choice1,choice2);
    }
public:
    bool PredictTheWinner(vector<int>& nums) {
        
        int n=nums.size();
        int best=solve(nums,0,n-1);
        
        int sum=0;
        for(int i=0;i<n;i++) sum+=nums[i];
        if(best>=sum-best){
            return true;
        }
        return false;
    }
};