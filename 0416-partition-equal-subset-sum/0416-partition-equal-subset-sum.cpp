class Solution {
public:
    bool canPartition(vector<int>& nums) 
    {
        int totalSum = 0;
        for (int num : nums) 
        {
            totalSum += num;
        }

        if (totalSum % 2 != 0) return false;

        int targetSum = totalSum / 2;

        vector<vector<int>> memo(nums.size(), vector<int>(targetSum + 1, -1));
        return dfs(nums, nums.size() - 1, targetSum, memo);
    }
    
    bool dfs(const vector<int>& nums, int index, int targetSum, vector<vector<int>>& memo) 
    {
        if (targetSum == 0) return true; 
        if (targetSum < 0 || index < 0) 
            return false;

        if (memo[index][targetSum] != -1) 
            return memo[index][targetSum];

        memo[index][targetSum] = dfs(nums, index - 1, targetSum - nums[index], memo) || dfs(nums, index - 1, targetSum, memo);

        return memo[index][targetSum];
    }
};