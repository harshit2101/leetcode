class TimeMap {
public:
    
    unordered_map<string, vector<pair<int, string>>> m;
    
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        m[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        if(m.find(key)==m.end()) return "";
        
        int l=0;
        int r=m[key].size()-1;
        string ans;
            
        if(m[key][0].first>timestamp) return "";
            
        while(l<=r){
            int mid=l + (r-l)/2;
            if(m[key][mid].first==timestamp){
                 return m[key][mid].second;
             }
            else if(m[key][mid].first<timestamp){
                ans=m[key][mid].second;
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        
        return ans;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */