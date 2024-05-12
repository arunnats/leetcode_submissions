const int ZERO = [](){
ios_base::sync_with_stdio(false);
cin.tie(nullptr);
return 0;
}();
class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        vector<vector<int>> ans(n-2, vector<int>(n-2));

        for(int i = 1; i < n-1; i++)
        {
            for(int j = 1; j < n-1; j++)
            {
                int currMax = 0;
                for(int k = i - 1; k <= i + 1; k++) 
                {
                    for(int l = j - 1; l <= j + 1; l++) 
                    {
                        currMax = max(currMax, grid[k][l]);
                    }
                }

                ans[i-1][j-1] = currMax;
            }
        }
        return ans;
    }
};