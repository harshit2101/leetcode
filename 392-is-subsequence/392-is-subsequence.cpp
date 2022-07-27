class Solution {
public:
    bool isSubsequence(string s, string t) {
        int sIndex = 0, tIndex = 0;
        while(tIndex < t.size() && sIndex < s.size()) {
            if(s[sIndex] == t[tIndex]) {
                sIndex++;
            }
            tIndex++;
        }
        return sIndex == s.size();
    }
};