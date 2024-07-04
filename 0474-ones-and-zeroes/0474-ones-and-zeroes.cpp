class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) 
    {
        vector<pair<int,int>> pairList;
        for (const auto& str : strs) 
        {
            int one = 0, zero = 0;
            for (const char& ch : str) 
            {
                if (ch == '1') 
                {
                    one++;
                } else 
                {
                    zero++;
                }
            }
            pairList.push_back({one, zero});
        }

        vector<vector<vector<int>>> memo(strs.size(), vector<vector<int>>(m + 1, vector<int>(n + 1, -1)));
        return dfs(pairList, 0, m, n, memo); 
    }

    int dfs(vector<pair<int,int>> &pairList, int index, int nZeros, int nOnes, vector<vector<vector<int>>>& memo) // memo passed by reference
    {
        int n = pairList.size();
        if(index == n || (nZeros == 0 && nOnes == 0))   
            return 0;

        if(memo[index][nZeros][nOnes] != -1)
            return memo[index][nZeros][nOnes];

        if(pairList[index].first > nOnes || pairList[index].second > nZeros)  
            return memo[index][nZeros][nOnes] = dfs(pairList, index + 1, nZeros, nOnes, memo);

        int include = 1 + dfs(pairList, index + 1, nZeros - pairList[index].second, nOnes - pairList[index].first, memo);
        int exclude = dfs(pairList, index + 1, nZeros, nOnes, memo);

        memo[index][nZeros][nOnes] = max(include, exclude);     
        return memo[index][nZeros][nOnes];
    }
};
