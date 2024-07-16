class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int N = nums1.size();
        int M = nums2.size();
        vector<vector<int>> memo (N+1, vector<int>(M+1, 0));

        int ans = 0;

        for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
                if (nums1[i - 1] == nums2[j - 1]) {
					memo[i][j] = memo[i - 1][j - 1] + 1;
					ans = max(ans, memo[i][j]);
                }
            }
        }

        return ans;
    }
};