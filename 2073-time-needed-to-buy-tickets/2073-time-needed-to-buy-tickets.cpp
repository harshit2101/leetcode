class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
       int res = 0,leng = tickets.size(),cur = tickets[k];
    for(int i=0;i<leng;i++){
        if(i<=k){
            res += min(cur,tickets[i]);
        } else {
            res += min(cur-1,tickets[i]);
        }
    }
    return res;
    
    }
};