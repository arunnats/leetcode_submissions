const int ZERO = [](){
ios_base::sync_with_stdio(false);
cin.tie(nullptr);
return 0;
}();
class Solution {
public:
    int findMin(vector<int>& nums) 
    {
        int l = 0;
        int r = nums.size()-1;
        int ans;
        while(l < r)
        {
            int mid = l + (r-l)/2;

            if(nums[mid] > nums[r])
            {
                l = mid + 1;
            }
            else if(nums[mid] < nums[l])
            {
                r = mid;
            }
            else
            {
                r--;
            }
        }
        return nums[l];
    }
};