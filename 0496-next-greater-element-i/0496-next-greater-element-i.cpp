class Solution 
{
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) 
    {
        vector<int> ans;

        for(const auto& num: nums1)
        {
            int nextMax = -1;
            int flag = 0;
            for(int i = 0; i < nums2.size(); i++)
            {
                if(nums2[i] == num)
                    flag = 1;
                else if(flag == 1 && nums2[i] > num)
                {
                    nextMax = nums2[i];
                    break;
                }
            }
            ans.push_back(nextMax);
        }

        return ans;
    }
};
