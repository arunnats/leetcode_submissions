class Solution {
public:
    int maxProduct(vector<int>& nums) 
    {
        if (nums.empty()) return 0;

        double  maxProd = nums[0];
        double  minProd = nums[0];
        double  ans = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < 0) {
                swap(maxProd, minProd);
            }

            maxProd = max(static_cast<double>(nums[i]), maxProd * nums[i]);
            minProd = min(static_cast<double>(nums[i]), minProd * nums[i]);

            ans = max(ans, maxProd);
        }

        return (int)(ans);    
    }
};
