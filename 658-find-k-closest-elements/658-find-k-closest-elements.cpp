class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        
        vector<int> ans;
        int s=0,e=arr.size()-1;
        
        while((e-s)>=k){
            if(abs(arr[s]-x)<=abs(arr[e]-x)) e--;
            else s++;
        }
        
        for(int i=s;i<=e;i++){
            ans.push_back(arr[i]);
        }
        
        return ans;
    }
};