class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<pair<int,int>> v;
        for(int i=0;i<nums.size();i++){
            for(auto x:nums[i]){
                v.push_back({x,i});
            }
        }
        sort(v.begin(),v.end());
        
        int i=0,j=0,count=0;
        int mini=INT_MAX;
        vector<int> ans;
        unordered_map<int,int> m;
        
        while(j<v.size()){
            m[v[j].second]++;
            if(m[v[j].second]==1) count++;
                        
            if(count==nums.size()){
                while(m[v[i].second]>1){
                    m[v[i].second]--;
                    i++;
                }
                if(mini>v[j].first-v[i].first){
                    mini=v[j].first-v[i].first;
                    ans=vector<int>{v[i].first,v[j].first};
                }
            }
            j++;
        }
        return ans;
    }
};
