class MyCircularDeque {
public:
    MyCircularDeque(int k) {
        nums = vector<int> (k, 0);
        lf = 0;
        rt = 0;
        length = 0;
    }
    
    bool insertFront(int value) {
        if(isFull())
            return false;
        
        length++;
        if(lf == 0)
            lf = nums.size();
        lf--;
        nums[lf] = value;
        return true;
    }
    
    bool insertLast(int value) {
        if(isFull())
            return false;
        
        length++;
        if(rt == nums.size())
            rt = 0;
        nums[rt] = value;
        rt++;
        return true;
    }
    
    bool deleteFront() {
        if(isEmpty())
            return false;
        
        length--;
        lf++;
        if(lf == nums.size()){
            lf = 0;
        }
        return true;
    }
    
    bool deleteLast() {
        if(isEmpty())
            return false;
        
        length--;
        if(rt == 0){
            rt = nums.size();
        }
        rt--;
        return true;
    }
    
    int getFront() {
        if(isEmpty())
            return -1;
        
        if(lf == nums.size())
            return nums[0];
        
        return nums[lf];
    }
    
    int getRear() {
        if(isEmpty())
            return -1;
        if(rt == 0)
            return nums.back();
        return nums[rt - 1];
    }
    
    bool isEmpty() {
        return length == 0;
    }
    
    bool isFull() {
        return length == nums.size();
    }
    
private:
    vector<int> nums;
    int lf, rt; // deque: [lf...rt)
    int length;
};
/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */