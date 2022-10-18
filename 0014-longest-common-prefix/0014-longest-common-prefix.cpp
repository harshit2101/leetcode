class Solution {
public:
    
//     int minLength(vector<string>& s){
        
//         int mini=s[0].size();
        
//         for(int i=1;i<s.size();i++){
//             if(s[i].size()<mini){
//                 mini=s[i].size();
//             }
//         }
        
//         return mini;
//     }
    
    string longestCommonPrefix(vector<string>& s) {
        
        sort(s.begin(),s.end());
        
        int mini=s[0].size();
        string ans="";
        char current;
        
        for(int i=0;i<mini;i++){
            
            current=s[0][i];
            
            for(int j=1;j<s.size();j++){
                if(s[j][i]!=current) return ans;
            }
            
            ans+=current;
        }
        
        return ans;
    }
};