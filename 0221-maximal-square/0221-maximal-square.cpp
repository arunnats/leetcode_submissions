class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) 
    {
        int ans = 0;
        int n = matrix.size();
        int m = matrix[0].size();

        if(n == 1 || m == 1)
        {
            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j < m; j++)
                {
                    if(matrix[i][j] == '1')
                        ans = 1;
                }
            }
            return ans;
        }

        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

        for(int r = 1; r <= n; r++)
        {
            for(int c = 1; c <= m; c++)
            {
                if(matrix[r-1][c-1] == '1')
                {
                    dp[r][c] = min(min(dp[r-1][c], dp[r][c-1]), dp[r-1][c-1]) + 1;
                    ans = max(ans, dp[r][c]);
                }
            }
        }

        return ans * ans;
    }
};