class MyCalendarThree {
    map<int, int> mp;
    int kBooking;
public:
    MyCalendarThree() {
        kBooking = 0;
    }
    
    int book(int start, int end) {
        mp[start] += 1;
        mp[end] -= 1;
        int cnt = 0;
        for(auto itr: mp){
            cnt += itr.second;
            kBooking = max(kBooking, cnt);
        }
        return kBooking;
    }
};
/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */