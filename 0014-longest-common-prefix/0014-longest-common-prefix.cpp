class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) 
    {
        int len = strs.size();
        string ans = "";

        if(len == 0)
            return ans;

        if(len == 1)
            return strs[0];

        sort(strs.begin(),strs.end());

        string first = strs[0];
        string last = strs[len-1];

        for(int i = 0; i < min(first.size(), last.size()); i++)
        {
            if(first[i] != last[i])
            {
                return ans;
            }
            ans = ans + first[i];
        }          
        return ans;
    }
};