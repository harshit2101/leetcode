class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        
        int n = nums.size();
        int runningSum = 0;
        int ans = 0;
        unordered_map<int, int> freq;
        // freq[0] = 1;
        for(int i = 0; i < n; i++) {
            runningSum += nums[i];
            int rem = runningSum % k;
            
            if(rem==0) ans++;
            
            if (rem < 0) {
                rem += k;
            }
            if (freq.find(rem) != freq.end()) {
               ans += freq[rem];
            }          
            freq[rem] += 1;     
        }       
        return ans;
    }
};