class Solution {
public:
    string removeOuterParentheses(string s)
    {
        // string ans = "";
        // stack <char> stackOne;
        // stack <char> stackTwo;
        // int l = 0;
        // int r = 0;
        // int n = s.size();

        // for(int i = 0; i < n; i++)
        // {
        //    char ch = s[i];

        //     if( ch == '(' )
        //     {
        //         l++;
        //         stackOne.push(ch);
        //     }
        //     else
        //     {
        //         r++;
        //         stackOne.push(ch);
        //     }

        //     if(l == r)
        //     {
        //         stackOne.pop();
        //         r--;

        //         for(int i = 0; i < (l+r); i++)
        //         {
        //             stackTwo.push(stackOne.top());
        //             stackOne.pop();
        //         }

        //         l = 0;
        //         r = 0;

        //         stackTwo.pop();
                
        //         while(!stackTwo.empty())
        //         {
        //             ans = ans + stackTwo.top();
        //             stackTwo.pop();
        //         }
        //     }
        // }

        // return ans;   

        string ans;
        int count = 0;

        for(const auto& ch : s)
        {
            if(ch == '(')
            {
                if(count > 0)
                    ans = ans + ch;
                count++;
            }
            else
            {
                count--;
                if(count > 0)
                {
                    ans = ans + ch;
                }
            }
        }

        return ans;
    }
};
