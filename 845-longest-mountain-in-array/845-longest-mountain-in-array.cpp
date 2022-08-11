class Solution {
public:
    int longestMountain(vector<int>& arr) {
        
        vector<int>dp1(arr.size(),0);  
        dp1[0]=1;
        
        for(int i=1;i<arr.size();i++)
        {
            if(arr[i-1]<arr[i])
            {
                dp1[i]=1+dp1[i-1];    
            }
            else
            {
                dp1[i]=1;
            }
        }
         
        vector<int>dp2(arr.size(),0); 
        dp2[dp2.size()-1]=1;
        
        for(int i=arr.size()-2;i>=0;i--)
        {
            if(arr[i+1]<arr[i])
            {
                dp2[i]=1+dp2[i+1];
            }
            else
            {
                dp2[i]=1;
            }
        }
        
        int ans=0;
        
        for(int i=0;i<dp1.size();i++)
        {
           if((dp1[i]+dp2[i]-1)>=3 and (dp1[i]+dp2[i]-1)>ans and dp1[i]!=1 and dp2[i]!=1)
           {
               ans=(dp1[i]+dp2[i]-1);
           }
        }
        return ans;
    }
};