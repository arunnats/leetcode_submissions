class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) 
    {
        unordered_map <int, int> freqMap;

        for(const auto & num : nums)
        {
            freqMap[num]++;
        }

        int ans = 0;
        
        for(const auto & pair : freqMap)
        {
            ans = ans + (pair.second * (pair.second-1)) / 2; 
        }

        return ans;
    }
};