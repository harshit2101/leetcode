class Solution {
public:
    
    void heapify(vector<int>& nums, int n, int i){
        int big=i, left=2*i+1, right=2*i+2;
        if(left<n && nums[left]>nums[big]){
            big=left;
        }
        if(right<n && nums[right]>nums[big]){
            big=right;
        }
        if(big!=i){
            swap(nums[i],nums[big]);
            heapify(nums,n,big);
        }
    }
    void buildHeap(vector<int>& nums, int n){
        for(int i=(n-2)/2;i>=0;i--){
            heapify(nums,n,i);
        }
    }
    void heapsort(vector<int>& nums, int n){
        buildHeap(nums,n);
        for(int i=n-1;i>=0;i--){
            swap(nums[i],nums[0]);
            heapify(nums,i,0);
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        int n=nums.size();
        heapsort(nums,n);
        return nums;
    }
};