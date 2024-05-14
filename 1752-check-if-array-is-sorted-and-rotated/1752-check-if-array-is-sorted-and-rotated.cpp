class Solution {
public:
    bool check(vector<int>& nums) 
    {
        int deltas  = 0;
        int n = nums.size();
    
        for(int i = 0; i < n; i++)
        {
            if(nums[i] > nums[(i + 1) % n])
                deltas++;

            if (deltas > 1) 
            {
                return false;
            }
        }   
        return true; 
    }
};