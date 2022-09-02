class Solution {
public:
    void solve(string ip, string op, vector<string> &ans)
    {
        //base case
        if(ip.size()==0)
        {
            ans.push_back(op);
            return;
        }
        if(isdigit(ip[0]))
        {
            string op1=op;
            op1.push_back(ip[0]);
            ip.erase(ip.begin());
            solve(ip,op1,ans);
        }
        else
        {
            string op1=op;
            string op2=op;
            op1.push_back(tolower(ip[0]));
            op2.push_back(toupper(ip[0]));
            ip.erase(ip.begin());
            solve(ip,op1,ans);
            solve(ip,op2,ans);
        }
        
    }
    
    vector<string> letterCasePermutation(string s) {
        vector<string> ans;
        string ip=s;
        string op="";
        solve(ip,op,ans);
        return ans;
    }
};