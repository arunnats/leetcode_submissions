class Solution {
public:
    int subarraySum(vector<int>& nums, int k) 
    {
        int n = nums.size();
        vector<int> preSum(n + 1, 0);

        for(int i = 1; i <= n; i++) 
        {
            preSum[i] = preSum[i-1] + nums[i-1]; 
        }

        int count = 0;

        for(int i = 0; i < n; i ++)
        {
            for(int j = i + 1; j <= n; j ++) 
            {
                if(preSum[j] - preSum[i] == k) 
                {
                    count++;
                }
            }
        }

        return count;
    }
};
