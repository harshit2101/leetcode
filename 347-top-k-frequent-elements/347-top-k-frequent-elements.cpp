class Solution {
public:
    
    typedef pair<int, int> pi;
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        int n=nums.size();
        for(auto x:nums){
            m[x]++;
        }
        
        priority_queue<pi,vector<pi>,greater<pi>> pq;
        
        for(auto i:m){
            pq.push({i.second,i.first});
            if(pq.size()>k) pq.pop();
        }
        vector<int> ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        
        return ans;
    }
};