class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<pair<int, int>, int>> q;
        vector<vector<int>> vis(n, vector<int>(m, 0)); 

        for(int i  = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j] == 2)
                {
                    q.push({{i , j}, 0});
                    vis[i][j] = 2;
                }
            }
        }

        int time = 0;

        vector<pair<int,int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        while(!q.empty()) 
        {
            pair<pair<int, int>, int> curr = q.front();
            int curTime = curr.second;
            pair<int, int> coords = curr.first;
            q.pop();

            time = max(time, curTime);

            for(auto it: dir)
            {
                int x = coords.first + it.first;
                int y = coords.second + it.second;

                if(x >= 0 && y >= 0 && x < n && y < m && vis[x][y] != 2 && grid[x][y] == 1)
                {
                    q.push({{x, y},curTime + 1});
                    vis[x][y] = 2;
                }
            }
        }

        for(int i = 0; i < n; i++) 
        {
            for(int j = 0; j < m; j++) 
            {
                if(grid[i][j] == 1 && vis[i][j] == 0) 
                    return -1;
            }
        }

        return time;
    }
};