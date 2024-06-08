class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) 
    {
        int n = grid[0].size();
        
        if( n == 1)
            return grid[0][0];

        int ans = INT_MAX;

        for(int i = 1; i < n; i++)
        {
            
            for(int j = 0; j < n; j++)
            {
                int minElem = INT_MAX;

                for(int k = 0; k < n; k++)
                {
                    if(k != j)
                        minElem = min(minElem, grid[i-1][k]);
                }

                grid[i][j] += minElem;  
            }
        }

        // for (const vector<int>& row : grid) {
        //     for (int element : row) {
        //         cout << element << " ";
        //     }
        //     cout << endl;  
        // }

        for(int i = 0; i < n; i++)
        {
            ans = min(ans, grid[n-1][i]);
        }

        return ans;
    }
};