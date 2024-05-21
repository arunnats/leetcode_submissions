class Solution {
public:
    vector<string> letterCombinations(string digits) 
    {
        unordered_map<char, string> keyboard = 
        {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };

        vector<string> ans;
        if(digits.size() == 0)
        {
            return ans;
        }

        string current;
        backtrack(ans, keyboard, digits, current, 0);
        return ans;
    }

    void backtrack(vector<string>& ans, unordered_map<char, string> keyboard, string digits, string current, int start)
    {
        if(current.size() == digits.size())
        {
            ans.push_back(current);
            return;
        }

        for(int i = start; i < digits.size(); i++)
        {
            char ch = digits[i];
            string nums = keyboard[ch];

            for(int j = 0; j < nums.size(); j++)
            {
                current = current + nums[j];
                backtrack(ans, keyboard, digits, current, i+1);
                current.pop_back();
            }
        }
    }

};