class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]%2==0) nums[i]=0;
            else{
                nums[i]=1;
            }
        }
        
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