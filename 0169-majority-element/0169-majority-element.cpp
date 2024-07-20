class Solution {
public:
    int majorityElement(vector<int>& nums) 
    {
        int count = 1;
        int ans = nums[0];

        for(int i = 1; i < nums.size(); i++)
        {
            if(nums[i] == ans){
                count++;
            } else {
                if(count > 0)
                {
                    count--;
                } else {
                    ans = nums[i];
                    count++;
                }
            }
        }

        return ans;
    }
};