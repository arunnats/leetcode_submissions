class Solution {
public:
    vector<vector<string>> partition(string s) 
    {
        vector<vector<string>> ans;
        vector<string> combination;
        string current;
        backtrack(ans, combination, current, s, 0);
        return ans;
    }

    void backtrack(vector<vector<string>>& ans, vector<string> combination, string current, string s, int start)
    {
        if(start == s.size())
        {
            ans.push_back(combination);
            return;
        }

        for(int i = start; i < s.size(); i++)
        {
            string current = s.substr(start, i - start + 1);

            if(palin(current))
            {
                combination.push_back(current);
                backtrack(ans, combination, current, s, i+1);
                combination.pop_back();
            }                
        }
    }

    bool palin(string s)
    {
        int l = 0;
        int r = s.size()-1;

        while(l <= r)
        {
            if(s[l] != s[r])
                return false;
            l++;
            r--;
        }
        
        return true;
    }
};