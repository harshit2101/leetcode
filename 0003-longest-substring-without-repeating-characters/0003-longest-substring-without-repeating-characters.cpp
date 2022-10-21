class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        unordered_map<char,int> m;
        int i=0, j=0, count=0;
        
        while(j<s.size()){
            
            m[s[j]]++;
            
            if(m.size()==j-i+1){
                count=max(count,j-i+1);
            }
            
            else{
                while(m.size()<j-i+1){
                    m[s[i]]--;
                    if(m[s[i]]==0) m.erase(s[i]);
                    i++;
                }
                
            }
            
            j++;
        }
        
        return count;
    }
};