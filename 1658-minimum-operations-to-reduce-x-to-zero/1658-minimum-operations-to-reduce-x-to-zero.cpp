class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int p=0,q=0,maxi=-1,cnt=0,tot=0;
        int n=nums.size();
       
        for(auto i:nums)
        tot+=i;
         if(tot<x)
        return -1;
        for(int i=0;i<nums.size();i++)
        {
           cnt+=nums[i];
           while(cnt>tot-x)cnt-=nums[p++];
           if(cnt==tot-x)
           maxi=max(maxi,i-p+1);
        }
        return (maxi==-1)?-1:n-maxi;
    }
       
};