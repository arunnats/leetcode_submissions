class Solution {
public:
    vector<string> generateParenthesis(int n) 
    {
        vector<string> ans;
        recurse(ans, 0, 0, "", n);
        return ans;
    }

    void recurse(vector<string>& ans, int left, int right, string s, int n)
    {
        if (s.length() == n * 2) 
        {
            ans.push_back(s);
            return;
        }

        if (left < n) 
        {
            recurse(ans, left + 1, right, s + "(", n);
        }
        
        if (right < left) 
        {
            recurse(ans, left, right + 1, s + ")", n);
        }
    }
};