class Solution {
public:
    string frequencySort(string s) 
    {
        unordered_map<int, int> map;
        int maxFreq = 0;
        string ans = "";

        for(const auto& ch : s)
        {
            map[ch]++;
        }

        for(const auto& pair : map)
        {
            maxFreq = max(maxFreq, pair.second);
        }     

        while(maxFreq > 0)
        {
            for(const auto& pair : map)
            {
                if(pair.second == maxFreq)
                {
                    ans.append(maxFreq, pair.first);
                }
            }
            maxFreq--;
        }

        return ans;
    }
};