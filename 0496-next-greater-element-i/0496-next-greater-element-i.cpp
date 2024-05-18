class Solution 
{
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) 
    {
        int n = nums1.size();
        vector<int> ans(n, -1);
        unordered_map<int, int> lookup;
        stack<int> indexStack;
        
        for(int i = 0; i < nums2.size(); i++ )
        {
            while(!indexStack.empty() && nums2[i] > nums2[indexStack.top()])
            {
                lookup[nums2[indexStack.top()]] = nums2[i];
                indexStack.pop();
            }
            indexStack.push(i);
        }

        for(int i = 0; i < n; i++)
        {
            if(lookup.find(nums1[i]) != lookup.end())
            {
                ans[i] = lookup[nums1[i]];
            }
        }

        return ans;
    }
};
