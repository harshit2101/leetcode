class Solution {
public:
    
    static bool comp(vector<int>& a, vector<int>& b){
        return a[1] > b[1];
    }
    
    int maximumUnits(vector<vector<int>>& b, int t) {
        sort(b.begin(),b.end(),comp);
        int ans=0;
        
        for(auto box:b){
            int mini=min(box[0],t);
            ans+=(mini*box[1]);
            t-=mini;
        }
        
        return ans;
    }
};