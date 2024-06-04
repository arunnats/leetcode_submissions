class Solution {
public:
    int numSquares(int n) 
    {
        vector<int> dp(n+1, INT_MAX);
        dp[0] = 1;

        vector<int> squares;
        for (int x = 1; (x * x) <= n; x++) 
            squares.push_back(x * x);

        for(int i = 1; i <= n; i++)
        {
            for(auto j: squares)
            {
               if((i-j) >=0)
                 dp[i] = min(dp[i], dp[i - j] + 1);
            }  
        }

        return dp[n]-1;
    }
};