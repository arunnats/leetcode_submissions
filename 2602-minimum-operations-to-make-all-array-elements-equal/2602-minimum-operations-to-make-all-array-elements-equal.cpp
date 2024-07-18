class Solution {
public:
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<long long> prefixSum(n, 0);
        prefixSum[0] = nums[0];

        for (int i = 1; i < n; ++i) {
            prefixSum[i] = prefixSum[i-1] + nums[i];
        }

        vector<long long> result;

        for (int q : queries) {

            int left = 0, right = n;
            while (left < right) {
                int mid = left + (right - left) / 2;
                if (nums[mid] < q) {
                    left = mid + 1;
                } else {
                    right = mid;
                }
            }

            int idx = left; 

            long long leftOperations = 0;
            long long rightOperations = 0;

            if (idx > 0) {
                leftOperations = (long long)q * idx - prefixSum[idx - 1];
            }

            if (idx < n) {
                rightOperations = (prefixSum[n - 1] - (idx > 0 ? prefixSum[idx - 1] : 0)) - (long long)q * (n - idx);
            }

            result.push_back(leftOperations + rightOperations);
        }

        return result;
    }
};