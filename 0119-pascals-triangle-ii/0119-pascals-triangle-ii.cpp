class Solution {
public:
    vector<int> getRow(int r) {
        vector<int> ans(r+1,0);
        long long x=1,n=r;
        
        for(int i=0;i<=r/2;i++,n--){
             
            ans[i]=x;
            ans[r-i]=x;
            x=x*n/(i+1);
         }
        return ans;
       
    }
};