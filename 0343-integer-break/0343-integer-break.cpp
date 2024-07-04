class Solution 
{
public:
    int integerBreak(int n) 
    {
        if(n==2) return 1;
        if(n==3) return 2;
        vector<int> dp(60, -1);
        return solve(n, dp);
    }

    int solve(int n, vector<int>& dp)
    {
        if(n==1) return 1;
        if(n==2) return 2;
        if(n==3) return 3;

        if(dp[n]!=-1) 
            return dp[n];
        
        int maxi = 0;

        for(int i = 1 ; i < n ; i++)
        {
            maxi = max(maxi , solve(n-i, dp) * solve(i, dp));
        }

        dp[n] = maxi;

        return dp[n];
    }
};