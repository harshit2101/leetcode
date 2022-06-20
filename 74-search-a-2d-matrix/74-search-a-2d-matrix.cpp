class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        
        int n=matrix.size();
        int m=matrix[0].size();
        
        int lo=0;
        int hi=(n*m)-1;
        
        while(lo<=hi){
            int mid= (lo + (hi - lo)/2);
            
            int ans=matrix[mid/m][mid%m];
            if(ans==target){
                return true;
            }
            
            if(ans<target){
                lo= mid + 1;
            }
            else{
                hi= mid - 1;
            }
        }
        
        return false;
    }
};