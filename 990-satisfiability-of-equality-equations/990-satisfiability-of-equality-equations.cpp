class Solution {
public:
    int find(vector<int> &arr, int x){
        if(x != arr[x]) arr[x] = find(arr, arr[x]);
        return arr[x];
    }
    bool equationsPossible(vector<string>& equations) {
        
        vector<int> arr(26,0);
        for(int i=0;i<26;i++){
            arr[i] = i;
        }
        
        for(auto x:equations){
            if(x[1]=='='){
                int ra = find(arr, x[0]-'a');
                int rb = find(arr, x[3]-'a');
                arr[ra] = rb;
            }
        }
        
        for(auto x:equations){
            if(x[1]=='!' && find(arr, x[0]-'a') == find(arr, x[3]-'a')){
                return false;
            }
        }
        
        return true;
        
        
        
        

        
    }
};