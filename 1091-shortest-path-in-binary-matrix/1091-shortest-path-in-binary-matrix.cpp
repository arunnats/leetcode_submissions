class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) 
    {
        int n = grid.size();

        if(grid[0][0]==1 || grid[n-1][n-1]==1)
            return -1;

        vector<vector<int>> vis(n, vector<int>(n, INT_MAX));

        queue<pair<int,pair<int,int>>> q;

        vis[0][0]=1;
        vector<pair<int,int>> dir={{0,1},{0,-1},{-1,0},{1,0},{1,1},{1,-1},{-1,1},{-1,-1}};

        q.push( {1,{0,0}} );

        while(!q.empty())
        {
            pair<int,pair<int,int>> curr = q.front();
            int dist = curr.first;
            pair<int, int> coords = curr.second;
            q.pop();

            for(auto it: dir)
            {
                int x = coords.first + it.first;
                int y = coords.second + it.second;

                if(x >=0 && x < n && y >=0 && y < n && grid[x][y] == 0)
                {
                    if(dist + 1 < vis[x][y])
                    {
                        vis[x][y] = dist + 1;
                        q.push({vis[x][y], {x,y}});
                    }
                }
            }
        }

        if(vis[n-1][n-1]!=INT_MAX)
        {
            return vis[n-1][n-1];
        }
        return -1;
    }
};