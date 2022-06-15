class Solution {
public:
    
    string solve(string s, int& pos) {
        
        int n = s.size(), num = 0;
        string ans = "";
        
        while(pos < n) {
            
            char cur = s[pos];
            if(isalpha(cur)) ans += cur;
            else if(isdigit(cur)) num = num * 10 + cur - '0';
            else if(cur == ']') return ans;
			// cur == '['
            else {
                string tmp = solve(s, ++pos);
                while(num--) ans += tmp;
                num = 0;
            }
            pos++;
        }
        
        return ans;
    }
    
    string decodeString(string s) {
        int i = 0;
        return solve(s, i);
    }
};