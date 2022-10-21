class Solution {
public:
    
    string solve(string& s,int i,int j){
        string temp="";
        
        while(i>=0 && i<s.size() && j>=0 && j<s.size() && s[i]==s[j]){
            i--;j++;
        }
        
        for(int k=i+1;k<=j-1;k++){
            temp+= s[k];
        }
        
        return temp;
    }
    
    string longestPalindrome(string s) {
        
        if(s.size()==1) return s;
        
        string ans="";
        
        for(int i=0;i<s.size();i++){
            string odd=solve(s,i,i);
            if(odd.size()>=ans.size()) ans=odd;
            if(i+1<s.size() && s[i]==s[i+1]){
                string even=solve(s,i,i+1);
                if(even.size()>=ans.size()) ans=even;
            }
        }
        
        return ans;
    }
};
