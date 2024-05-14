class Solution {
public:
    int findLHS(vector<int>& nums) 
    {
        map<int, int> freqMap;
        set<int> numList;

        for(const auto& num : nums)
        {
            freqMap[num]++;
            numList.insert(num);
        }
        
        int LHS = 0;
        for(const auto& num: numList)
        {
            int Ifreq = 0;
            int I1freq = 0;

            if(freqMap.count(num) > 0 && freqMap.count(num-1) > 0)
            {
                Ifreq = freqMap[num];
                I1freq = freqMap[num-1];
            }

            LHS = max( LHS, Ifreq + I1freq );
        }

        return LHS;

    }
};