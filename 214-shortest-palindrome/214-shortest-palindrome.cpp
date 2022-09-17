class Solution {
public:
    string shortestPalindrome(string s) {
        string t = s+"$";
        reverse(s.begin(),s.end());
        t = t+s;
        int n = t.size();
        vector<int>lps(n,0);
        int i=1,j=0;
        while(i<n && j<n){
            if(t[i]==t[j]){
                lps[i] = j+1;
                i++;j++;
                
            }
            else{
                if(j>0){
                    j = lps[j-1];
                }
                else{
                    i+=1;
                }
            }
        }
        
        string str = s.substr(0,s.size()-lps[n-1]);
        reverse(s.begin(),s.end());
        
        str = str+s;
        
        return str;
    }
};