class Solution {
public:
    int subarraySum(vector<int>& nums, int k) 
    {
        int n = nums.size();
        unordered_map<int, int> preSumFreq;
        int preSum = 0;
        int count = 0;

        preSumFreq[0] = 1;

        for(int i = 0; i < n; i++) 
        {
            preSum = preSum + nums[i];

            if(preSumFreq.find(preSum-k) != preSumFreq.end())
            {
                count = count + preSumFreq[preSum - k];
            }

            preSumFreq[preSum]++;
        }

        return count;
    }
};
