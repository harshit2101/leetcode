
class Solution {
public:
    
    bool check(string& s1, string& s2){
        if(s1.size()!= s2.size()+1) return false;
        int first=0,second=0;
        while(first<s1.size()){
            if(s1[first]==s2[second]){
                first++;
                second++;
            }
            else{
                first++;
            }
        }
        
        if(first==s1.size() && second==s2.size()) return true;
        return false;
    }
    
    
    static bool comp(string& a, string& b){
        return a.size()<b.size();
    }
    
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        vector<int> dp(n,1);
        int maxi=1;
        
        sort(words.begin(),words.end(),comp);
        
        for(int ind = 1;ind<n;ind++){
            for(int prev =0;prev<ind;prev++){
                if(check(words[ind], words[prev])){
                    dp[ind]=max(dp[ind],1+dp[prev]);
                }
             }
            maxi = max(maxi,dp[ind]);
        }
        return maxi;
	}
};