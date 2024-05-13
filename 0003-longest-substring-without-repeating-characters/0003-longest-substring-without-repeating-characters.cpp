class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int maxLength = 0;
        unordered_map<char, int> map;
        int l = 0;

        for(int r = 0; r < n; r ++)
        {
            if(map.count(s[r]) ==0 || map[s[r]] < l)
            {
                map[s[r]] = r;
                maxLength = max(maxLength, r - l + 1);
            }
            else
            {
                l = map[s[r]] + 1;
                map[s[r]] = r;
            }
        }
        return maxLength;
    }   
};