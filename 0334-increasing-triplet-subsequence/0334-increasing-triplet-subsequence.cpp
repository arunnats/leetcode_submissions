class Solution {
public:
    bool increasingTriplet(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int> cond(n,0);

        if(n < 3)
            return false;

        int currMin = nums[0];
        int currMax = nums[n-1];
        
        for(int i = 1; i < n-1; i++)
        {
            if(nums[i] > currMin)
                cond[i]++;
            currMin = min(currMin, nums[i]);
        }

        for(int i = n-2; i > 0; i--)
        {
            if(nums[i] < currMax)
            {
                cond[i]++;
                if(cond[i] == 2)
                    return true;
            }
            currMax = max(currMax, nums[i]);
        }
        return false;
    }
};