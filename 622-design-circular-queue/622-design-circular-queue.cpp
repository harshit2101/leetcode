class MyCircularQueue {
int currCapacity = 0, maxCapacity, *data, frontPos = 0, rearPos = 0;
public:
    MyCircularQueue(int k) {
        maxCapacity = k;
        data = new int[k];     
    }
    
    bool enQueue(int value) {
        if (isFull()) return false;
        currCapacity++;
        data[rearPos++] = value;
        if (rearPos == maxCapacity) rearPos = 0;
        return true;
    }
    
    bool deQueue() {
        if (isEmpty()) return false;
        currCapacity--;
        frontPos++;
        if (frontPos == maxCapacity) frontPos = 0;
        return true;
    }
    
    int Front() {
        if (isEmpty()) return -1;
        return data[frontPos];
    }
    
    int Rear() {
        if (isEmpty()) return -1;
        return data[!rearPos ? maxCapacity - 1 : rearPos - 1];
    }
    
    bool isEmpty() {
        return !currCapacity;
    }
    
    bool isFull() {
        return currCapacity == maxCapacity;
    }
};
/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */