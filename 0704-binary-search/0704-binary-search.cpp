const int ZERO = [](){
ios_base::sync_with_stdio(false);
cin.tie(nullptr);
return 0;
}();
class Solution {
public:
    int search(vector<int>& nums, int target) 
    {
        int left = 0, right = nums.size();

        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] > target) right = mid;
            else if (nums[mid] < target) left = mid + 1;
            else return mid;
        }
        return -1;
    }
};