class Solution {
public:
    int longestSubstring(string s, int k) {
        int n=s.size();
        if(n==0 || n<k) return 0;
        if(k<=1) return n;
        
        unordered_map<char,int> c;
        for(auto x:s) c[x]++;
        
        int l=0;
        while(l<n && c[s[l]]>=k) l++;
        if(l>=n-1) return l;
        
        int l1=longestSubstring(s.substr(0,l),k);
        while(l<n && c[s[l]]<k)l++;
        int l2= (l<n)?longestSubstring(s.substr(l),k):0;
        return max(l1,l2);
        
    }
};