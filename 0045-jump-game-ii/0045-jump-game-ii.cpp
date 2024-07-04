class Solution {
public:
    int jump(vector<int>& nums) 
    {
        int ans = 0;
        int end = 0;
        int reach = 0;

        for (int i = 0; i < nums.size() - 1; i++) 
        {
            reach = max(reach, i+nums[i]);

            if(reach >= nums.size() - 1)
            {
                ans++;
                break;
            }
            if(i == end)
            {
                ans++;
                end = reach;
            }
        }

        return ans;
    }
};