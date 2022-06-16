class Solution {
public:
    string longestPalindrome(string s) {
       
        int l_res = 0;
        int r_res = 0;
        int res_size = 0;
        
        for (int i = 0; i < s.size(); i++){
            //cout << "odds \n";

            int l = i;
            int r = i;
            while ( l >= 0 && r < s.size() && s[l] == s[r]){
                
                //cout << r - l + 1 << " " << res_size << '\n';
                //cout << s[l] << ' ' << s[r] << ' ' << s.substr(l_res, r_res) << "\n";
                if ((r - l + 1) > res_size){
                    l_res = l;
                    r_res = r;
                    res_size = r - l + 1;
                }
                
                l--;
                r++;
            }
            
        }
        
        for (int i = 0; i < s.size(); i++){
            //cout << "evens \n";
            int l = i;
            int r = i+1;
            while ( l >= 0 && r < s.size() && s[l] == s[r]){
                
                //cout << s[l] << ' ' << s[r] << ' ' << s.substr(l_res, r_res) << "\n";
                if ((r - l + 1) > res_size){
                    l_res = l;
                    r_res = r;
                    res_size = r - l + 1;
                }
                
                l--;
                r++;
            }
            
        }
        
        return s.substr(l_res, res_size);
        // go to the center
        
        
    }
};