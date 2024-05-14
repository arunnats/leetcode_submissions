class Solution {
public:
    string longestNiceSubstring(string s) 
    {
        int n = s.size();
        int maxLen = 0;
        int startIndex = 0;
        
        for(int i = 0; i < n; i++)
        {
            int lowerCase=0;
            int upperCase=0;
            for(int j = i; j < n; j++)
            {
                if( s[j] >= 'a')
                    lowerCase = lowerCase | ( 1<<( s[j]-'a' ) );
                else
                    upperCase = upperCase | ( 1<< (s[j]-'A' ) );

                if ((lowerCase^upperCase)==0)
                {
                    if (maxLen<j-i+1)
                    {
                        startIndex=i;
                        maxLen=j-i+1;
                    }
                }

            }
        }
        if (maxLen==0)
            return "";
        return s.substr(startIndex,maxLen);
    }
};