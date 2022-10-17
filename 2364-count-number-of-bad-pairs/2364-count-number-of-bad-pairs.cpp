class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        
        unordered_map<int,long long> count;
        long long n=nums.size();
        long long total = (n*(n-1))/2;
        
        
        for(int i=0;i<nums.size();i++){
            count[nums[i]-i]++;
        }
        
        long long goodpairs=0;
        for(auto it:count) goodpairs+=(it.second*(it.second-1))/2;
        
        return total-goodpairs;
    }
};