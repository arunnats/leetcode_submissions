class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) 
    {
        unordered_map<int, int> freqMap;
        int n = nums.size();

        for(int i = 0; i < n; i++)
        {
            if(i > k)
                freqMap[nums[i-k-1]]--; 
            if(freqMap[nums[i]] > 0) 
                return true;
            freqMap[nums[i]]++; 
        }
        return false;
    }
};
