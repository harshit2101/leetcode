class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<int,int> m;
        for(auto& x: s){
            m[x]++;
        }
        int ans;
        bool flag=true;
        for(int i=0;i<s.size();i++){
            if(m[s[i]]==1){
                ans=i;
                flag=false;
                break;
            }
        }
        if(flag) return -1;
        return ans;
    }
};