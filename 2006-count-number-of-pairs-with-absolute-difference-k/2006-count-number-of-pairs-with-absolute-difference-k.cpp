class Solution {
public:
    int countKDifference(vector<int>& nums, int k) 
    {
        unordered_map<int, int> map;
        int ans = 0;

        for(int num : nums) {
            if(map.find(num + k) != map.end()) {
                ans += map[num + k];
            }
            if(map.find(num - k) != map.end()) {
                ans += map[num - k];
            }
            map[num]++;
        }

        return ans;
    }
};