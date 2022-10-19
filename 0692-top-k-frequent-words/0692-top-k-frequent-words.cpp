
class comp{
    
    public:
    bool operator()(pair<int,string>& a, pair<int,string>& b){
        if(a.first>b.first) return true;
        if(a.first==b.first && a.second<b.second) return true;
        return false;
    }
    
};

class Solution {
public:
    
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        
        unordered_map<string,int> mp;
        
        for(int i=0;i<words.size();i++){
            mp[words[i]]++;
        }
        
        priority_queue<pair<int,string>,vector<pair<int,string>>, comp> pq;
        
        for(auto it: mp){
            pq.push({it.second, it.first});
            if(pq.size()>k) pq.pop();
        }
        
        vector<string> ans;
        
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        
        reverse(ans.begin(),ans.end());
        
        return ans;
        
    }
};