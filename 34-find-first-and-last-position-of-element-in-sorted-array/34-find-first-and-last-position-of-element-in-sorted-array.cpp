class Solution {
    
public:
    int last(vector<int>&nums,int target){
        
        int s=0,e=nums.size()-1;
        int mid,ans=-1;
        while(s<=e){
            mid=s+(e-s)/2;
            
            if(target==nums[mid]){
                ans=mid;
                s=mid+1;
            }
            else if(target<nums[mid]) e=mid-1;
            else s=mid+1;
        }
        return ans;
    }    
    
    int first(vector<int>& nums,int target){
    
        int s=0,e=nums.size()-1;
        int mid,ans=-1;
        while(s<=e){
            mid=s+(e-s)/2;
            
            if(target==nums[mid]){
                ans=mid;
                e=mid-1;
            }
            else if(target<nums[mid]) e=mid-1;
            else s=mid+1;
        }
        return ans;
}
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int f=first(nums,target);
        int l=last(nums,target);
        return {f,l};
    }
};