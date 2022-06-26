class Solution {
public:
    int characterReplacement(string s, int k) {
        
        int i=0,j=0,maxi=0;
        int ans=-1;
        unordered_map<char,int> m;
        while(j<s.size()){
            m[s[j]]++;
            maxi=max(maxi,m[s[j]]);
            if((j-i+1)-maxi>k){
                m[s[i]]--;
                i++;
            }
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};