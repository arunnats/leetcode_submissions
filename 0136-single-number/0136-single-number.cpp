class Solution {
public:
    int singleNumber(vector<int>& nums) 
    {
        ios::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        int ans = 0;
        for(const auto& num:nums)
        {
            ans = ans ^ num;
        }
        return ans;
    }
};