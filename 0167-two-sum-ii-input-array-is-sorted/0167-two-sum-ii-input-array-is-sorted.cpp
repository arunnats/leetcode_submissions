class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) 
    {
        vector<int> ans;
        int l = 0;
        int r = numbers.size()-1;

        while(l < r)
        {
            if(numbers[l] + numbers[r] == target)
            {
                ans.push_back(l+1);
                ans.push_back(r+1);
                return ans;
            }
            else if(numbers[l] + numbers[r] > target)
                r--;
            else if(numbers[l] + numbers[r] < target)
                l++;
        }

        return ans;
    }
};