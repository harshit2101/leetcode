class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int i=0,profit=0,buy,sell;
        
        while(i<n-1){
            while(i<n-1 && prices[i+1]<=prices[i]) i++;
            
            buy=prices[i];
            
            while(i<n-1 && prices[i+1]>prices[i]) i++;
            
            sell=prices[i];
            
            profit+=sell-buy;
        }
        
        return profit;
    }
};