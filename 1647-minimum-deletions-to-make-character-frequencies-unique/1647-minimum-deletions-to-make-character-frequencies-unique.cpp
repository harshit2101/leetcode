class Solution {
public:
    int minDeletions(string s) {
        vector<int> freq(26,0);
        
        for(auto x:s){
            freq[x-'a']++;
        }
        
        sort(freq.begin(),freq.end(),greater<int>());
        int ans=0;
        int f=freq[0];
        for(auto x:freq){
            if(x>f){
                if(f>0)ans+=(x-f);
                else ans+=x;
            }
            f=min(f-1,x-1);
        }
        return ans;
    }
};