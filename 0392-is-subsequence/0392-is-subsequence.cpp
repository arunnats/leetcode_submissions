class Solution {
public:
    bool isSubsequence(string s, string t) 
    {
        int sIndex = 0, tIndex = 0;
        int sSize = s.size(), tSize = t.size();

        while (sIndex < sSize && tIndex < tSize) 
        {
            if (s[sIndex] == t[tIndex]) 
            {
                sIndex++;
            }
            tIndex++;
        }

        return sIndex == sSize;
    }
};
