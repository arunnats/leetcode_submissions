class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) 
    {
        return helper(nums, k) - helper(nums, k-1);
    }

    int helper(vector<int>& nums, int k) 
    {
        int l = 0; 
        int ans = 0; 
        int count = 0;

        for(int r = 0; r < nums.size(); r++)
        {
            if(nums[r] % 2 == 1)
            {
                count++;
            }

            while(count >k)
            {
                if (nums[l] % 2 == 1) 
                    count--; 
                l++;
            }

            ans = ans + (r - l + 1);
        }

        return ans;
    }
};