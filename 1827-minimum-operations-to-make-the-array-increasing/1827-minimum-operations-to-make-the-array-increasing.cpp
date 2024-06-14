class Solution {
public:
    int minOperations(vector<int>& nums) 
    {
        // if(nums.size() == 1)
        // {
        //     return 0;
        // }

        int count = 0;

        // for(int i = 1; i < nums.size(); i++)
        // {
        //     while(nums[i] <= nums[i-1])
        //     {
        //         nums[i]++;
        //         count++;
        //     }
        // }    

        for(int i = 0; i < nums.size() -1; i++)
        {
            if(nums[i] < nums[i+1])
            {
                continue;
            }
            else
            {
                int diff = nums[i] - nums[i+1];
                diff++;
                nums[i+1] += diff;
                count += diff;
            }
        }

        return count;
    }
};

auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();