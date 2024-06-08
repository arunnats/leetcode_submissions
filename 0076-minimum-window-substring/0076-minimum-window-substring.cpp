class Solution {
public:
    string minWindow(string s, string t) 
    {
        if (s.empty() || t.empty() || s.length() < t.length()) 
        {
            return "";
        }

        std::vector<int> map(128, 0);
        int count = t.length();

        int l = 0;
        int r = 0;
        int minLen = INT_MAX;
        int startIndex = 0;

        for (char c : t) 
        {
            map[c]++;
        }

        while (r < s.length())
        {
            if(map[s[r]] > 0)
            {
                count--;
            }
            map[s[r]]--;  
            r++;

            while (count == 0)
            {
                if(r - l < minLen)
                {
                    startIndex = l;
                    minLen = r - l;
                }

                map[s[l]]++;  
                if (map[s[l]] > 0) 
                {
                    count++;
                }
                l++;
            }
        }   

        return minLen == INT_MAX ? "" : s.substr(startIndex, minLen);
    }
};
