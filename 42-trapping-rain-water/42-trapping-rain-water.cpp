class Solution {
public:
    int trap(vector<int>& height) {
        
        int st=0,lmax=0,rmax=0,res=0,en=height.size()-1;
        while(st<=en) {
            if(height[st] <= height[en]) {
                if(lmax<=height[st]) 
                    lmax = height[st];
                else
                    res+=lmax-height[st];
                st++;
            }
            else {
                if(rmax<=height[en]) 
                    rmax = height[en];
                else
                    res+=rmax-height[en];
                en--;
            }
            
        }
        return res;
    }
};