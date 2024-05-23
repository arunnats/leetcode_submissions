class Solution {
public:
    bool canJump(vector<int>& nums) 
    {
        vector<int> memo(nums.size(), -1);
        return backtrack(nums, 0, memo);
    }

    bool backtrack(vector<int>& nums, int pos,  vector<int>& memo)
    {
        if (pos >= nums.size() - 1) {
            return true;
        }

        if (nums[pos] == 0) {
            return false;
        }

        if (memo[pos] != -1) {
            return memo[pos] == 1;
        }

        for (int i = 1; i <= nums[pos]; ++i) 
        {
            if (backtrack(nums, pos + i, memo)) 
            {
                memo[pos] = 1; 
                return true;
            }
        }
        memo[pos] = 0;
        return false;
    }
};