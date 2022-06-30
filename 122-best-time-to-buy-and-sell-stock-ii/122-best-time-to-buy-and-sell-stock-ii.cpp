class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0, prev = prices[0];

        for (int i = 1; i < prices.size(); ++i)
        {
            if (prev < prices[i])  
                profit += prices[i] - prev; 
            prev = prices[i];
        }

        return profit;
    }
};