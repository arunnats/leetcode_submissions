class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> ans;
        unordered_map<int, int> freqMap;

        int minRow = INT_MAX;

        for(int i = 0; i < m; i++)
        {
            minRow = INT_MAX;
            for(int j = 0; j < n; j++)
            {
                minRow = min(minRow, matrix[i][j]);
            } 
            freqMap[minRow]++;
        }

        int maxCol = INT_MIN;

        for(int i = 0; i < n; i++)
        {
            maxCol = INT_MIN;
            for(int j = 0; j < m; j++)
            {
                maxCol = max(maxCol, matrix[j][i]);
            } 
            freqMap[maxCol]++;
        }

        for(const auto& mapPair: freqMap)
        {
            if(mapPair.second == 2)
                ans.push_back(mapPair.first);
        }

        return ans;
    }
};