class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        vector<vector<int>> ans;
        vector<int> combination;
        int currentSum = 0;
        backtrack(ans, candidates, target, combination, currentSum);
        return ans;    
    }

    void backtrack(vector<vector<int>>& ans, vector<int> candidates, int target, vector<int> combination, int currentSum)
    {
        if(currentSum > target)
        {
            return;
        }
        if(currentSum == target)
        {
            ans.push_back(combination);
            return;
        }

        for(int i = 0; i < candidates.size(); i++)
        {
            if(combination.empty() || candidates[i] >= combination.back())
            {
                combination.push_back(candidates[i]);
                currentSum += candidates[i];
                backtrack(ans, candidates, target, combination, currentSum);
                combination.pop_back();
                currentSum -= candidates[i];
            }
        }
    }
};