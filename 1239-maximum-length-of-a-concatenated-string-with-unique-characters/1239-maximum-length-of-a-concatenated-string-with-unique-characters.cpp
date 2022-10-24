class Solution {
public:
    int ans=0;
    
    bool unique(string& s){
        vector<int> v(26,0);
        
        for(int i=0;i<s.size();i++){
            if(v[s[i]-'a']>0) return false;
            v[s[i]-'a']++;
        }
        
        return true;
    }
    
    void solve(vector<string>& arr, string temp, int itr){
        
        if(!unique(temp)) return;
        if(temp.size()>ans) ans=temp.size();
        
        if(itr>=arr.size()) return;
        
        solve(arr, temp+arr[itr], itr+1);
        solve(arr, temp, itr+1);
    }
    
    int maxLength(vector<string>& arr) {
        
        solve(arr,"",0);
        return ans;
    }
};