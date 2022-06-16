class Solution {
public:
    string longestPalindrome(string s) {
        string manacher_str = "#";
        for (int i = 0; i<s.size(); i++)
            manacher_str = manacher_str + s[i] + "#";
        int len = manacher_str.size();
        vector<int> RL(len, 0);
        int pos = 0, maxRight = 0;
        int maxLen = 0, maxLenPos = 0;//maxLen:
        for (int i = 0; i<len; i++) {
            if (i<maxRight)
                RL[i] = min(RL[2 * pos - i], maxRight - i);
            else
                RL[i] = 1;
            while (i - RL[i] >= 0 && i + RL[i]<len && manacher_str[i + RL[i]] ==manacher_str[i - RL[i]])
                RL[i]++;
            if (RL[i]>maxLen) {
                maxLen = RL[i];
                maxLenPos = i;
            }

            if (i + RL[i]>maxRight) {
                maxRight = i + RL[i];
                pos = i;
            }
        }
        s = "";
        for (int i = maxLenPos - maxLen + 1; i<maxLenPos + maxLen - 1; i++)
            if (manacher_str[i] != '#')
                s += manacher_str[i];
        return s;
    }
};