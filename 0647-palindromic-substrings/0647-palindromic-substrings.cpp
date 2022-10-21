class Solution {
public:
    
    int solve(string s, int i,int j,int &count){
        while(i>=0 && i<s.size() && j>=0 && j<s.size() && s[i]==s[j]){
            count++;
            i--;
            j++;
        }
        
        return count;
    }
    
    int countSubstrings(string s) {
        
        int count=0;
        
        for(int i=0;i<s.size();i++){
            int odd=solve(s,i,i,count);
            int even=solve(s,i,i+1,count);
        }
        
        return count;
    }
};