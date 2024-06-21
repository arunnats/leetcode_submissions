class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) 
    {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;

        vector<vector<int>> vis (m, vector<int>(n, 0));

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if (vis[i][j] == 0 && grid[i][j] == 1) 
                {
                    ans = max(ans, sizeCalculation(grid, vis, i, j));
                }
            }
        }

        return ans;
    }

    int sizeCalculation(vector<vector<int>>& grid, vector<vector<int>>& vis, int i, int j)
    {
        int m = grid.size();
        int n = grid[0].size();

        if(i < 0 || j < 0 || i >= m || j >= n || vis[i][j] == 1 || grid[i][j] == 0)
            return 0;

        vis[i][j] = 1;
        int sum = 1;
        
        vector<pair<int,int>> coords = {{0,1}, {0,-1}, {1,0}, {-1,0}};

        for(auto it: coords)
        {
            int x = it.first + i;
            int y = it.second + j;

            sum = sum + sizeCalculation(grid, vis, x, y);
        }
        
        
        return sum ;
    }
};