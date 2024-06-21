class Solution {
public:
    int numIslands(vector<vector<char>>& grid) 
    {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;

        vector<vector<int>> vis (m, vector<int>(n, 0));

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if (vis[i][j] == 0 && grid[i][j] == '1') 
                {
                    markAsVis(grid, vis, i, j);
                    ans++;
                }
            }
        }

        return ans;
    }

    void markAsVis(vector<vector<char>>& grid, vector<vector<int>>& vis, int i, int j)
    {
        int m = grid.size();
        int n = grid[0].size();

        if(i < 0 || j < 0 || i >= m || j >= n || vis[i][j] == 1 || grid[i][j] == '0')
            return;

        vis[i][j] = 1;
        
        vector<pair<int,int>> coords = {{0,1}, {0,-1}, {1,0}, {-1,0}};

        for(auto it: coords)
        {
            int x = it.first + i;
            int y = it.second + j;

            markAsVis(grid, vis, x, y);
        }
    }
};