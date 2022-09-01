class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n=nums.size(); vector<vector<int>>v;
        if(nums.empty())
            return v;
       sort(nums.begin(),nums.end());
        int i=0,j=i+1,left=0,right=(n-1);
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int left=j+1;
                int right=n-1;
                long long target2= (long long)target- nums[i]-nums[j];
                while(left<right)
                {
                    int target3= nums[left]+nums[right];
                    if(target3>target2)
                    {
                        right--;
                    }
                    else if(target3<target2)
                    {
                        left++;
                        
                    }
                    else
                    {
                        vector<int>quad(4,0);
                        quad[0]=nums[i];
                        quad[1]=nums[j];
                        quad[2]=nums[left];
                        quad[3]=nums[right];
                        v.push_back(quad);
                    
                    while(left<right&& nums[left]==quad[2])
                        left++;
                        while(left<right && nums[right]==quad[3])
                            right--;
                }
                }
                while((j+1)<n&&nums[j+1]==nums[j])
                    j++;
            }
            while((i+1)<n&&nums[i]==nums[i+1])
                i++;
        }
        return v;
    }
};