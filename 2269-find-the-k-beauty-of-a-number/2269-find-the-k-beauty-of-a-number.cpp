class Solution {
public:
    int divisorSubstrings(int num, int k) {
        string s=to_string(num);
        int n=s.size();
        int c=0;
        for(int i=0;i<=n-k;i++){
            
                if(stoi(s.substr(i,k))!=0){
                    if(num%stoi(s.substr(i,k))==0){
                        c++;
                     
                    }
                }
            
        }
        return c;
    }
};