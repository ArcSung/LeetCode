class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        
        if(prices.size() == 0)
            return 0;
        
        int cur = prices[0];
        prices.push_back(0);
        
        for(int i = 1; i < prices.size(); i++){
            if(prices[i] < prices[i-1]){
                profit += prices[i-1] - cur;
                cur = prices[i];
            }
            
        }
        
        
        return profit;
    }
};
