class segmentTree{
    public:
    vector<int> arr;
    vector<int> seg;
    
    segmentTree(vector<int>& nums){
        for(auto it: nums){
            arr.push_back(it);
        }
        int n=nums.size();
        for(int i=0; i<4*n; i++){ seg.push_back(0); }
    }
    
    int buildHelper(int segIdx, int low, int high){
        if(low==high){ // we are at leaf node of segment tree
            seg[segIdx]=arr[low];
            return arr[low];
        }
        
        int mid= low+(high-low)/2;
        int leftSum= buildHelper(2*segIdx+1, low, mid);
        int rightSum= buildHelper(2*segIdx+2, mid+1, high);
        
        seg[segIdx]=leftSum+rightSum;
        return seg[segIdx];
    }
    int build(){
        return buildHelper(0, 0, arr.size()-1);
    }
    
    void updateHelper(int segIdx, int low, int high, int pos, int diff){
        if(low>high){ return; }
        if(pos<low || pos>high){ return; }
        
        // Reached here --> pos is inside [low,high]
        if(low==high && low==pos){
            seg[segIdx]+=diff; return;
        }
        
        seg[segIdx]+=diff;
        int mid= low+(high-low)/2;
        updateHelper(2*segIdx+1, low, mid, pos, diff);
        updateHelper(2*segIdx+2, mid+1, high, pos, diff);
        
        return;
    }
    void update(int pos, int val){
        int diff= val-arr[pos];
        arr[pos]=val;
        return updateHelper(0, 0, arr.size()-1, pos, diff);
    }
    
    int getSumHelper(int segIdx, int low, int high, int l, int r){
        if(low>high){ return 0; }
        
        if(low>=l && high<=r){ // total overlap
            return seg[segIdx];
        }
        else if(high<l || low>r){ // no overlap
            return 0;
        }
        
        //partial Overlap
        int mid=low+(high-low)/2;
        int sumLeft= getSumHelper(2*segIdx+1, low, mid, l, r);
        int sumRight= getSumHelper(2*segIdx+2, mid+1, high, l, r);
        
        return sumLeft+sumRight;
    }
    int getSum(int l, int r){
        return getSumHelper(0, 0, arr.size()-1, l, r);
    }
};

class NumArray {
public:
    segmentTree* segTree;
    NumArray(vector<int>& nums) {
        segTree= new segmentTree(nums);
        int a= segTree->build();
    }
    
    void update(int index, int val) {
        segTree->update(index, val);
    }
    
    int sumRange(int left, int right) {
        int sum= segTree->getSum(left, right);
        return sum;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */