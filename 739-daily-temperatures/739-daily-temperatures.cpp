class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        
        int n=temp.size();
        int hottest=INT_MIN;
        vector<int> ans(n,0);
        
        for(int i=n-1;i>=0;i--){
            
           if(hottest<=temp[i]){
               hottest=temp[i];
           }
            
            else{
                int j=i+1;
                while(temp[j]<=temp[i]){
                    j+=ans[j];
                }
                
                ans[i]=j-i;
            }
            
        }
        
        return ans;
    }
};