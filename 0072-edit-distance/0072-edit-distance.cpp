class Solution {
public:
    int minDistance(string word1, string word2) 
    {
        int n = word1.size();
        int m = word2.size();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        return util(word1, word2, n - 1, m - 1, dp);
    }

    int util(string& S1, string& S2, int i, int j, vector<vector<int>>& dp)
    {
        if (i < 0)
            return j + 1;
        if (j < 0)
            return i + 1;
        
        if (dp[i][j] != -1)
            return dp[i][j];
        
        if (S1[i] == S2[j]){
            dp[i][j] = 0 + util(S1, S2, i - 1, j - 1, dp);
            return dp[i][j];
        }else{
            dp[i][j] = 1 + min(util(S1, S2, i - 1, j - 1, dp), min(util(S1, S2, i - 1, j, dp) , util(S1, S2, i, j - 1, dp)));
            return dp[i][j];
        }
    }
};