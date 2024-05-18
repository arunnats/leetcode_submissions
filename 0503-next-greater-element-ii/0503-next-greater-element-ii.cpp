class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) 
    {
        int n = nums.size();
        vector <int> ans(n, -1);
        stack <int> monoStack;
        
        for (int i = 0; i < n; i++)
        {
            nums.push_back(nums[i]);
        }

        for (int i = 0; i < 2*n; i++)
        {
            while(!monoStack.empty() && nums[monoStack.top()] < nums[i])
            {
                ans[monoStack.top()] = nums[i];
                monoStack.pop();
            }

            if (i < n) 
            {
                monoStack.push(i);
            }
        }

        return ans;
    }
};