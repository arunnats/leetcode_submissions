class Solution {
public:
    int calPoints(vector<string>& operations) 
    {
        int ans = 0;

        stack<int> scoreStack;

        for( const auto& op: operations )    
        {
            if(op[0] == 'D')
            {
                scoreStack.push( scoreStack.top() * 2 );
            }
            else if(op[0] == 'C')
            {
                scoreStack.pop();
            }
            else if(op[0] == '+')
            {
                int first = scoreStack.top();
                scoreStack.pop();
                int second = scoreStack.top();
                scoreStack.pop();

                scoreStack.push(second);
                scoreStack.push(first);
                scoreStack.push(first + second);             
            }
            else
            {
                scoreStack.push(stoi(op));
            }
        }

        while(!scoreStack.empty())
        {
            ans = ans + scoreStack.top();
            scoreStack.pop();
        }

        return ans;
    }
};