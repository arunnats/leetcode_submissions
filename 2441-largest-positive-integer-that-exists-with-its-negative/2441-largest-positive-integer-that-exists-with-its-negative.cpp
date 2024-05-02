class Solution 
{
public:
    int findMaxK(vector<int>& nums) 
    {
        if (nums.size() == 0 || nums.size() == 1 )
            return -1;

        sort(nums.begin(), nums.end()); 
        int l = 0;
        int r = nums.size() - 1;

        while(l < r)
        {
            if(nums[l] + nums[r] == 0)
                return nums[r];

            else if(nums[l] + nums[r] > 0)
                r--;

            else if(nums[l] + nums[r] < 0)
                l++;
        }
        
        return -1;        
    }
};