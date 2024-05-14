class Solution {
public:
    int findLHS(vector<int>& nums) 
    {
        // map<int, int> freqMap;
        // set<int> numList;

        // for(const auto& num : nums)
        // {
        //     freqMap[num]++;
        //     numList.insert(num);
        // }
        
        // int LHS = 0;
        // for(const auto& num: numList)
        // {
        //     int Ifreq = 0;
        //     int I1freq = 0;

        //     if(freqMap.count(num) > 0 && freqMap.count(num-1) > 0)
        //     {
        //         Ifreq = freqMap[num];
        //         I1freq = freqMap[num-1];
        //     }

        //     LHS = max( LHS, Ifreq + I1freq );
        // }

        // return LHS;

        sort(nums.begin(), nums.end());

        int l = 0; 
        int n  = nums.size();
        int LHS = 0;

        for(int r = 0; r < n; ++r)
        {
            while (nums[r] - nums[l] > 1 )
            {
                l++;
            }
            if(nums[r] - nums[l] == 1)
            {
                LHS = max(LHS, r - l + 1);
            }
         
        }
        return LHS;
    }
};