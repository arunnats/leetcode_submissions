auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) 
    {
        int n = nums.size();

        if(n < 2)
            return false;

        // for(int i = 0; i < n; i++)
        // {
        //     int sum = 0;
        //     for(int j = i; j < n; j ++)
        //     {
        //         sum = sum + nums[j];   

        //         cout<< sum << "\n" ;

        //         if(j - i + 1 >= 2 && sum >= k && sum % k == 0)
        //         {
        //             return true;
        //         }
        //         else if(j - i + 1 >= 2 && sum == 0)
        //         {
        //             return true;
        //         }
        //     }
        // }

        unordered_map<int, int> remainderMap;

        remainderMap[0] = -1;
        
        int prefixSum = 0;

        for(int i = 0; i < n; ++i)
        {
            prefixSum += nums[i];
            int remainder = prefixSum % k;

            if(remainderMap.find(remainder) != remainderMap.end())
            {
                 if(i - remainderMap[remainder] > 1)
                {
                    return true;
                }
            }
            else
            {
                remainderMap[remainder] = i;
            }

        }

        return false;
    }
};