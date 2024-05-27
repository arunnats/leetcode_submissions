class Solution {
public:
    int rob(vector<int>& nums) 
    {
        int n = nums.size();
        if(n == 1)
            return nums[0];
        if(n == 2)
            return max(nums[0], nums[1]);

        vector<int> dp(n);

        dp[0] = nums[0];
        dp[1] = nums[1];

        int idx_max = (dp[0] > dp[1]) ? 0 : 1; 
        int idx_nextmax = 1 - idx_max;

        for(int i = 2; i < n; i++)
        {
            if(idx_max != i-1)
            {
                dp[i] = nums[i] + dp[idx_max];
                if(dp[i] > dp[idx_max])
                {
                    idx_nextmax = idx_max;
                    idx_max = i;
                }
            }
            else
            {
                dp[i] = nums[i] + dp[idx_nextmax];
                if(dp[i] > dp[idx_max])
                {
                    idx_nextmax = idx_max;
                    idx_max = i;
                }
                else if(dp[i] > dp[idx_nextmax]) 
                {
                    idx_nextmax = i; 
                }
            }
        }

        for(auto num: dp)
            cout << num <<" ";
        return dp[idx_max];
    }
};