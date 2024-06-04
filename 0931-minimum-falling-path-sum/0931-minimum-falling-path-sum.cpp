class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) 
    {
        int n = matrix[0].size();
        
        if( n == 1)
            return matrix[0][0];

        int ans = INT_MAX;

        for(int i = 1; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                int minElem = INT_MAX;

                for(int k = max(0, j-1); k <= min(n-1, j+1); k++)
                {
                    minElem = min(minElem, matrix[i-1][k]);
                }

                matrix[i][j] += minElem;  
            }
        }

        for (const vector<int>& row : matrix) {
            for (int element : row) {
                cout << element << " ";
            }
            cout << endl;  
        }

        for(int i = 0; i < n; i++)
        {
            ans = min(ans, matrix[n-1][i]);
        }

        return ans;
    }
};