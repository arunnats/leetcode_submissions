class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) 
    {
        int rows = grid.size(), columns = grid[0].size();
        vector<vector<int>> sums(rows, vector<int>(columns, 0));

        int i;
        sums[0][0] = grid[0][0];

        for(i = 1; i < rows; i++) 
            sums[i][0] = grid[i][0] + sums[i - 1][0];
        for(i = 1; i < columns; i++) 
            sums[0][i] = grid[0][i] + sums[0][i - 1];
        
        for(i = 1; i < rows; i++)
        {
            for(int j = 1; j < columns; j++)
            {
                sums[i][j] = grid[i][j] + min(sums[i - 1][j], sums[i][j - 1]);
            }
        }

        return sums[rows - 1][columns - 1];
    }
};