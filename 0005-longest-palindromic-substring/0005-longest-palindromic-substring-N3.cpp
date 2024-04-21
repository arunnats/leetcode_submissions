class Solution 
{
public:
    bool isPalindrome(const string& s, int start, int end) 
    {
        while (start < end) 
        {
            if (s[start++] != s[end--]) 
            {
                return false;
            }
        }
        return true;
    }

    string longestPalindrome(string s) 
    {
        int maxLen=0;
        int startIndex = 0;
        int n = s.length();

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(isPalindrome(s, i, j))
                {
                    int currentLen = j - i + 1;
                    if(currentLen > maxLen)
                    {
                        maxLen = currentLen;
                        startIndex = i;
                    }
                }
            }
        }
        
        return s.substr(startIndex, maxLen);
    }
};