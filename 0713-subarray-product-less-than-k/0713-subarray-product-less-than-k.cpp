class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) 
    {
        if (k <= 1) return 0;

        int ans = 0;
        int n = nums.size();
        int l = 0;
        int prod = 1;

        for(int r = 0; r < n; r++){
            prod *= nums[r];

            while (prod >= k && l <= r) {
                prod /= nums[l];
                l++;
            }
            
            ans += (r - l + 1);
        }

        return ans;    
    }
};