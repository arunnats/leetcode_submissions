class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int maxMax = 0;
        int minMin = 0;
        int currMax = 0;
        int currMin = 0;

        for (const auto num : nums) {
            currMax = max(num, currMax + num);
            maxMax = max(maxMax, currMax);
            currMin = min(num, currMin + num);
            minMin = min(minMin, currMin);
        }

        return max(abs(minMin), maxMax);
    }
};