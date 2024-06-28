class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) 
    {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector<vector<int>> memo(m, vector<int>(n, -1)); 
        return dp(0 ,0 ,m, n, memo, obstacleGrid);
    }

    int dp(int x, int y, int m, int n, vector<vector<int>>& memo, vector<vector<int>>& obstacleGrid)
    {
        if (x >= m || y >= n || obstacleGrid[x][y] == 1)
            return 0;
        
        if (x == m - 1 && y == n - 1)
            return 1;
            
        if (memo[x][y] != -1)
            return memo[x][y];

        memo[x][y] = dp(x+1, y, m, n, memo, obstacleGrid) + dp(x, y+1, m, n, memo, obstacleGrid);

        return memo[x][y];
    }
};