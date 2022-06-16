class Solution {
public:
    string convert(string s, int nRows) {
        if(s.empty()||nRows<2) return s;
        
        vector<string> zig(nRows);
        bool down = true;
        for(int i = 0; i < s.size(); ++i)
        {
            int row = i%(nRows - 1);
            if(down)
                zig[row].push_back(s[i]);

            else
                zig[nRows - 1 - row].push_back(s[i]);
            if(row==nRows - 2)
                down = !down;
        }
        string res;
        for(auto& temp: zig)
            res += temp;
        return res;
    }

};