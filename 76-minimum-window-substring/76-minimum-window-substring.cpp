class Solution {
public:
    string minWindow(string s, string t) {
        int i=0,j=0;
        int n1=s.size(),n2=t.size();
        
        if(n2>n1) return "";
        
        unordered_map<char,int> m;
        for(auto x:t){
            m[x]++;
        }
        
        int mini=INT_MAX;
        int c=m.size();
        string ans="";
        
        while(j<n1){
            if(m.find(s[j])!=m.end()){
                m[s[j]]--;
                if(m[s[j]]==0) c--;
            }
            
            while(c==0){
                if(mini>j-i+1){
                    mini=min(mini,j-i+1);
                    ans=s.substr(i,j-i+1);
                }
                if(m.find(s[i])!=m.end()){
                    m[s[i]]++;
                    if(m[s[i]]>0){
                        c++;
                    }
                }
                i++;
            }
            j++;
        }
        return ans;
    }
};