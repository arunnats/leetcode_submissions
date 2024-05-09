class Solution {
public:
    void rotate(vector<int>& nums, int k) 
    {
        int n = nums.size();
        vector<int> rotated(n);

        k = k % n;

        for(int i = 0; i < k; i++)
        {
            rotated[i] = nums[n - k + i];
        }

        for(int i = 0; i < n-k; i++)
        {
            rotated[k + i] = nums[i];
        }

        nums = rotated;
    }
};