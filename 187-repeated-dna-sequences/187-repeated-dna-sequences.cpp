class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> ans;
        
        if(s.size()<=10) return ans;
        unordered_map<string,int> m;
        for(int i=0;i<=s.size()-10;i++){
            string st=s.substr(i,10);
            m[st]++;
        }
        
        for(auto& x:m){
            if(x.second>1){
                ans.push_back(x.first);
            }
        }
        
        return ans;
    }
};