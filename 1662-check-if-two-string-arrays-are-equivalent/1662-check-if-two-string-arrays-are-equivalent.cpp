class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        
        string temp1="", temp2="";
        
        for(auto it:word1) temp1+=it;
        for(auto it:word2) temp2+=it;
        
        if(temp1.size()!=temp2.size()) return false;
        
        bool flag=true;
        
        for(int i=0;i<temp1.size();i++){
            if(temp1[i]!=temp2[i]){
                return false;
            }
        }
        
        return true;
    }
};