class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int n=height.size();
        int s=0,e=n-1;
        int ans=0;
        
        while(s<e){
            int mini=min(height[s],height[e]);
            ans=max(ans,mini*(e-s));
            
            if(height[s]<height[e]) s++;
            else e--;
        }
        
        return ans;
    }
};