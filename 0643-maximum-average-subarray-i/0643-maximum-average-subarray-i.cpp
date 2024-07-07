class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double ave = 0.0;
        int n = nums.size();
        double ans;

        for(int i = 0; i < k; i++)
        {
            ave += nums[i];
        }

        ave /= k;
        ans = ave;

        for(int i = k; i < n; i++)
        {
            ave *= k;
            ave += nums[i];
            ave -= nums[i-k];
            ave /= k;
            ans = max(ans, ave);
        }

        return ans;
    }
};