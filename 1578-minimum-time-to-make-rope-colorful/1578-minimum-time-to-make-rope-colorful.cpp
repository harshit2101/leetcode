class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        
        int ans=0, costprev=0;
        char prevch='*';
        
        
        for(int i=0;i<colors.size();i++){
            if(colors[i]==prevch){
                
                if(costprev<neededTime[i]){
                    ans+= costprev;
                    costprev=neededTime[i];
                }
                
                else{
                    ans+=neededTime[i];
                }
            }
            
            else{
                prevch=colors[i];
                costprev=neededTime[i];
            }
        }
        
        return ans;
    }
};