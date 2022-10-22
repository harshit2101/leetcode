class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int i=0,j=height.size()-1;
        int ans=0;
        
        while(i<j){
            
            int mini=min(height[i],height[j]);
            ans=max(ans,mini*(j-i));
            
            if(height[i]<height[j]){
                // temp=height[i];
                i++;
            }
            else{
                // temp=height[j];
                j--;
            }
            
        }
        
        return ans;
    }
};