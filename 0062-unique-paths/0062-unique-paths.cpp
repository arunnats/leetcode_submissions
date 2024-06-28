class Solution {
public:
    int uniquePaths(int m, int n) 
    {
        vector<vector<int>> memo (m, vector<int>(n, 0));
        return dp(0 ,0 ,m, n, memo);
    }

    int dp(int x, int y, int m, int n, vector<vector<int>>& memo)
    {
        if(x >= m || y >= n)
            return 0;
        
        if(memo[x][y])
            return memo[x][y];

        if(x == m-1 || y == n-1)
            return 1;

        memo[x][y] = dp(x+1, y, m, n, memo) + dp(x, y+1, m, n, memo);

        return memo[x][y];
    }
};