class Solution {
public:
    int findDuplicate(vector<int>& nums) 
    {
        unordered_map <int, int> map;

        for(const auto& num: nums)
        {
            map[num]++;
            if(map[num] > 1)
            {
                return num;
            }
        }

        return -1;
    }
};