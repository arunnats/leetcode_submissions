class Solution {
public:
    string mergeAlternately(string word1, string word2) 
    {
        const int n = min(word1.length(), word2.length());
        string pre;

        for (int i = 0; i < n; ++i) 
        {
            pre += word1[i];
            pre += word2[i];
        }
        return pre + word1.substr(n) + word2.substr(n);
    }
};