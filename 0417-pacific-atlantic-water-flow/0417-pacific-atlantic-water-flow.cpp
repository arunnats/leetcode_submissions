class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) 
    {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> ans;

        vector<vector<int>> count(n, vector<int>(m, 0));
        vector<vector<bool>> vis_pac(n, vector<bool>(m, false));
        vector<vector<bool>> vis_atl(n, vector<bool>(m, false));
        
        for(int i = 0; i < m; i++)
        {
            pair<int, int> coord = {0, i};

            if(vis_pac[0][i] == false)
            {
                DFS(heights, coord, vis_pac, count, 0);
            }
        }

        for(int i = 0; i < n; i++)
        {
            pair<int, int> coord = {i, 0};
            
            if(vis_pac[i][0] == false)
            {
                DFS(heights, coord, vis_pac, count, 0);
            }
        }

        for(int i = 0; i < m; i++)
        {
            pair<int, int> coord = {n-1, i};

            if(vis_atl[n-1][i] == false)
            {
                DFS(heights, coord, vis_atl, count, 1);
            }
        }

        for(int i = 0; i < n; i++)
        {
            pair<int, int> coord = {i, m-1};
            
            if(vis_atl[i][m-1] == false)
            {
                DFS(heights, coord, vis_atl, count, 1);
            }
        }

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(count[i][j] == 2)
                {
                    ans.push_back({i, j});
                }
            }
        }

        return ans;
    }

    void DFS(vector<vector<int>>& heights, pair<int, int> coord, vector<vector<bool>>& vis, vector<vector<int>>& count, int ocean)
    {
        int n = heights.size();
        int m = heights[0].size();
        int row = coord.first;
        int col = coord.second;

        vis[row][col] = true;
        count[row][col]++;

        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        for(const auto& dir : directions)
        {
            int newRow = row + dir.first;
            int newCol = col + dir.second;
            if(newRow >= 0 && newRow < n && newCol >= 0 && newCol < m &&
               !vis[newRow][newCol] && heights[newRow][newCol] >= heights[row][col])
            {
                DFS(heights, {newRow, newCol}, vis, count, ocean);
            }
        }
    }
};