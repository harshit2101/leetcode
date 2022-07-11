class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        
        int n=arr.size();
        vector<int>ans;
        int start=0,end=n-1;
        while((end-start)>=k){
            if(abs(arr[start]-x) > abs(arr[end]-x)){
                start++;
            }
            else{
                end--;
            }
        } 
        for(int i=start;i<=end;i++){
            ans.push_back(arr[i]);
        }
        return ans;
    }
};