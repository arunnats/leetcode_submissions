class Solution {
public:
    int coinChange(vector<int>& coins, int amount) 
    {
        vector<int> dp(amount+1,INT_MAX); 
        dp[0] = 0;

        for(int target = 1; target <= amount; target++)
        {
            for (int coin : coins) 
            {
                if (coin <= target && dp[target - coin] != INT_MAX)
                {
                    dp[target] = min(dp[target], dp[target - coin] + 1);
                }
            }
        }

        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};