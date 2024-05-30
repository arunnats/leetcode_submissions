const int ZERO = [](){
ios_base::sync_with_stdio(false);
cin.tie(nullptr);
return 0;
}();
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) 
    {
        if(nums.size() == 0)
            return {-1,-1};

        vector<int> ans;

        ans.push_back(findLeftLimit(nums, target));
        ans.push_back(findRightLimit(nums, target));
        
        return ans;
    }

    int findLeftLimit(vector<int>& nums, int k)
    {
        int l = 0;
        int r = nums.size()-1;
        int flag = 0;

        int leftBound = INT_MAX;

        while(l<=r)
        {
            int mid = (l + r)/2;
            
            if(nums[mid] == k)
            {
                leftBound = min(leftBound, mid);
                r = mid - 1;
                flag = 1;
            }
            else if(nums[mid] > k)
                r = mid - 1;
            else
                l = mid + 1; 
        }

        if (flag == 0)
            return -1;

        return leftBound;
    }

    int findRightLimit(vector<int>& nums, int k)
    {
        int l = 0;
        int r = nums.size()-1;
        int flag = 0;
        
        int rightBound = INT_MIN;

        while(l<=r)
        {
            int mid = (l + r)/2;
            
            if(nums[mid] == k)
            {
                rightBound = max(rightBound, mid);
                l = mid + 1;
                flag = 1;
            }    
            else if(nums[mid] > k)
                r = mid - 1;
            else
                l = mid + 1; 
        }

        if (flag == 0)
            return -1;

        return rightBound;
    }
};