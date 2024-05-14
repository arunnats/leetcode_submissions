class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) 
    {
        int n = nums.size();
        int ans = 0;
        int prefixSum = 0;
        unordered_map<int,int> map;
        map[0] = 1;

        for(int i = 0; i < n; i++)
        {
            prefixSum = prefixSum + nums[i];

            if(map.find(prefixSum-goal) != map.end())
            {
                ans = ans + map[prefixSum - goal];
            }

            map[prefixSum]++;
        }

        return ans;
    }
};