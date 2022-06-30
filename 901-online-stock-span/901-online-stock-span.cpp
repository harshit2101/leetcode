class StockSpanner {
public:
    stack<pair<int,int>> s; 
    int i=0;
    StockSpanner() {
       
    }
    
    int next(int price) {
        int span;
        while(!s.empty() && s.top().first<=price)
            s.pop();
        if(!s.empty()){
            span=s.top().second;
        }
        
        else{
            span=-1;
        }
        
        s.push({price,i});
        span=i-span;
        i++;
        
        return span;
    }
};
/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */