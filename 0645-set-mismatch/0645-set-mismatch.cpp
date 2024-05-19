class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int> ans;
        unordered_map<int, int> freqMap;
        int expectedSum = n*(n+1)/2;
        int sum = 0;
        for(int i = 0; i < n; i++)
        {
            freqMap[nums[i]]++;
            if(freqMap[nums[i]] > 1)
                ans.push_back(nums[i]);
            sum += nums[i];
        }
        ans.push_back(expectedSum - sum + ans[0]);

        return ans;
    }
};