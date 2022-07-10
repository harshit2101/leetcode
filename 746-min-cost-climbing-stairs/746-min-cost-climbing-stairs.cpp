class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        
        int n=cost.size();
        vector<int> mini=cost;
        for(int i=2;i<n;i++){
            mini[i]+=min(mini[i-1],mini[i-2]);
        }
        
        return min(mini[n-1],mini[n-2]);
    }
};