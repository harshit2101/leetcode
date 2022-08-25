class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
    
        unordered_map<char,int> m;
             
        for(auto y: magazine){
            m[y]++;
        }
        
        for(int i=0;i<ransomNote.size();i++){
            if(m[ransomNote[i]]>0) m[ransomNote[i]]--;
            else{
                return false;
            }
        }
        
        return true;
    }
};