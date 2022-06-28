class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size()>s2.size()) return false;
        
        int i=0,j=0;
        int k=s1.size();
        unordered_map<char,int> m;
        for(auto x:s1){
            m[x]++;
        }
        
        int c=m.size();
        
        while(j<s2.size()){
            
            if(m.find(s2[j])!=m.end()){
                m[s2[j]]--;
                if(m[s2[j]]==0){
                    c--;
                }
            }
            
            if(j-i+1<k) j++;
            
            else if(j-i+1==k){
                if(c==0){
                    return true;
                }
                if(m.find(s2[i])!=m.end()){
                    m[s2[i]]++;
                    if(m[s2[i]]==1){
                        c++;
                    }
                }    
                i++;
                j++;
            }
        }
        
        return false;
    }
};