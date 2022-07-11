class Solution {
public:
    string frequencySort(string s) {
        
        unordered_map<char,int> m;
        int n=s.size();
        for(auto x:s){
            m[x]++;
        }
        
        priority_queue<pair<int,char>> pq;
        
        for(auto i:m){
            pq.push({i.second,i.first});
        }
        
        string ans="";
        while(!pq.empty()){
            int freq=pq.top().first;
            int chars=pq.top().second;
            
            for(int i=1;i<=freq;i++){
                ans+=chars;
            }
            pq.pop();
        }
        
        return ans;
    }
};