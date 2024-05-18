class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) 
    {
        stack<int> indexStack;
        int n = prices.size();
        vector <int> ans(n);
        
        for(int i = 0; i < n; i++)
        {
            if(indexStack.empty())
            {
                indexStack.push(i);
            }
            else
            {
                while(!indexStack.empty() && prices[i] <= prices[indexStack.top()])
                {
                    ans[indexStack.top()] = prices[indexStack.top()] - prices[i];
                    indexStack.pop();
                }
                indexStack.push(i);
            }
        }
        while(!indexStack.empty())
        {
            ans[indexStack.top()] = prices[indexStack.top()];
            // cout << prices[indexStack.top()] << "\n";
            indexStack.pop();
        }
        return ans;
    }
};