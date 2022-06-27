class Solution {
public:
    int minPartitions(string n) {
        int c=0;
        for(int i=0;i<n.size();i++){
            c=max(c,n[i]-'0');
        }
        return c;
    }
};