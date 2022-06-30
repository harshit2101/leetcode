class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        
        int n=temp.size();
        
        vector<int> ans(n,0);
        
        for(int i=n-1;i>=0;i--){
            
            int j=i+1;
            while(j<n && temp[j]<=temp[i]){
                if(ans[j]>0){
                    j+=ans[j];
                }
                else{
                    j=n;
                }
            }
         
            if(j<n){
                ans[i]=j-i;
            }
        }
        
        return ans;
    }
};