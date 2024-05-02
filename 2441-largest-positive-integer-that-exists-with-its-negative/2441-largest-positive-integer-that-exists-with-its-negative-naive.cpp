class Solution 
{
public:
    int findMaxK(vector<int>& nums) 
    {
        int maxAns = -1;

        for(int i = 0; i < nums.size(); i++)
        {
            for(int j = 0; j < nums.size(); j++)
            {
                if(nums[i] == -1*nums[j])
                {
                    maxAns = max(maxAns, nums[i]); 
                }
            }
        }

        return maxAns;
    }
};