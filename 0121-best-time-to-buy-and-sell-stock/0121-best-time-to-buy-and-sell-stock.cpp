class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // int maxProfit = 0;
        // for (int i = 0; i < prices.size(); i++) {
        //     for (int j = i; j < prices.size(); j++) {
        //         if(prices[i] < prices[j])
        //         {
        //             int profit = prices[j] - prices[i];
        //             if(profit > maxProfit)
        //                 maxProfit = profit;
        //         }
        //     }
        // }

        int leastBuyPrice = 100000;
        int maxProfit = 0;
        int profit = 0;

        for(int i = 0; i < prices.size(); i++)
        {
            if(prices[i] < leastBuyPrice)
                leastBuyPrice = prices[i];
            profit = prices[i] - leastBuyPrice;
            if(maxProfit < profit)
                maxProfit = profit;
        }

        return maxProfit;
    }
};