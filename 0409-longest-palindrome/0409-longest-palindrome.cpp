class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> map;
        int len=0;
        int largest_odd = 0;

        for(const auto& ch : s)
            map[ch]++;

        for(const auto& count : map)
        {
            if(count.second %2 != 0)
            {
                if(count.second > largest_odd)
                {
                    largest_odd = count.second;
                }
            }
        }
        
        for(const auto& count : map)
        {
            len += count.second / 2 * 2;
        }

        len = len + largest_odd;
        len = len - largest_odd / 2 *2;

        return len;

    }
};