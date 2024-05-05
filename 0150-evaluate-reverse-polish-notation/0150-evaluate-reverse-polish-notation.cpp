class Solution 
{
public:
    int evalRPN(vector<string>& tokens) 
    {
        stack <int> stack;

        for(const auto& token : tokens) {
            if (token == "+" || token == "-" || token == "/" || token == "*") {
                int second = stack.top();
                stack.pop();

                int first = stack.top();
                stack.pop();

                if (token == "+") 
                {
                    stack.push(first + second);
                } 
                else if (token == "-") 
                {
                    stack.push(first - second);
                } 
                else if (token == "*") 
                {
                    stack.push(first * second);
                } 
                else if (token == "/") 
                {
                    stack.push(first / second);
                }
            }
            else 
            {
                stack.push(stoi(token));
            }
        }
        return stack.top();
    }
};