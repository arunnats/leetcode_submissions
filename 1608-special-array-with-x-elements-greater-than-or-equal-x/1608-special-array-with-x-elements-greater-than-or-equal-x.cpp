class Solution {
public:
    int specialArray(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end()); 

        int n = nums.size();
        
        for(int x = 0; x <= n; x++) 
        {
            int count = countGreaterOrEqual(nums, x);
            if(count == x)  
                return x;
        }
        return -1;  
    }

    int countGreaterOrEqual(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;

        while (l <= r) 
        {
            int mid = l + (r - l) / 2;  

            if (nums[mid] >= target) 
            {
                r = mid - 1;  
            } 
            else 
            {
                l = mid + 1; 
            }
        }

        return nums.size() - l;
    }
};
