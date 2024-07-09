class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> memo(n, vector<vector<int>>(3, vector<int>(2, -1)));
        return bfs(prices, 0, 0, 2, memo);
    }

    int bfs(vector<int>& prices, int index, int holding, int transactionsLeft, vector<vector<vector<int>>>& memo) {
        if (index >= prices.size() || transactionsLeft == 0) {
            return 0;
        }   

        if (memo[index][transactionsLeft][holding] != -1) {
            return memo[index][transactionsLeft][holding];
        }

        int doNothing = bfs(prices, index + 1, holding, transactionsLeft, memo);
        int doSomething = 0;

        if (holding) {
            doSomething = prices[index] + bfs(prices, index + 1, 0, transactionsLeft - 1, memo);
        } else {
            doSomething = -prices[index] + bfs(prices, index + 1, 1, transactionsLeft, memo);
        }

        memo[index][transactionsLeft][holding] = max(doNothing, doSomething);
        return memo[index][transactionsLeft][holding];
    }
};