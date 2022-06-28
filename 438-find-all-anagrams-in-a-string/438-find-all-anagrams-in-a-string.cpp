class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int i=0,j=0;
        vector<int> ans;
        int k=p.size();
        unordered_map<char,int> m;
        for(auto x:p){
            m[x]++;
        }
        
        int c=m.size();
        
        while(j<s.size()){
            
            if(m.find(s[j])!=m.end()){
                m[s[j]]--;
                if(m[s[j]]==0){
                    c--;
                }
            }
            
            if(j-i+1<k) j++;
            
            else if(j-i+1==k){
                if(c==0){
                    ans.push_back(i);
                }
                if(m.find(s[i])!=m.end()){
                    m[s[i]]++;
                    if(m[s[i]]==1){
                        c++;
                    }
                }    
            i++;
            j++;
            }
        }
        
        return ans;
    }
};