class Solution {
public:
    
    void solve(int n,int open,int close, string temp, vector<string>& ans){
        if(temp.size()==2*n){
            ans.push_back(temp);
            return;
        }
        
        if(open<n){
            temp+='(';
            solve(n,open+1,close,temp,ans);
            temp.pop_back();
        }
        
        if(close<open){
            temp+=')';
            solve(n,open,close+1,temp,ans);
            temp.pop_back();
        }
        
        return;
    }
    
    vector<string> generateParenthesis(int n) {
        
        vector<string> ans;
        solve(n,0,0,"",ans);
        return ans;
    }
};